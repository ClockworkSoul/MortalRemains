// File: /std/monster.c
// The monster body is from the TMI-2 lib. Part of the bodies project and
// implemented by Watcher@TMI-2 and Mobydick@TMI-2. The code contained
// in this object is heavily based on code found in the original user.c
// and monster.c at TMI.
//
// The relevant code headers follow:
// Original author of monster.c: Huma@TMI.
// Subsequent work done by Buddha@TMI-2 and Mobydick@TMI-2.
// Original authors of user.c were Sulam@TMI and Buddha@TMI.
// Many other people have added to this as well.
// This file has a long revision history dating back to the hideous
// mudlib.n and is now probably not at all the same.
// This file is part of the TMI distribution mudlib.
// Please keep this header with any code within.
//
// leto might have fixed type checking, might have killed it ;)
// 97-03-07  Cyanide added set_level() function.
// 97-10-12  Cyanide TOTALLY redid damage messages and added a total of 9 
//            (count 'em: 9!) "miss" messages.  Just 1 was BORING!
// 97-10-13  Cyanide added experience point sharing for parties in die().
// 97-11-08  Cyanide thinks he finalized the protectors dilemma.
// 97-01-06  Cyanide added support for the new MIN to move_player().
// 98-04-05  Chronos added arm() and wear() functions.
// 98-04-05  Cyanide thinks he fixed move_around() func.
// 98-06-03  Cyanide fixed the whole "following" thing. Now
//           it works through move_around() instead of _go.c
// 98-03-07  Cyanide made arm() set the skill in monsters.
// 99-05-07  Cyanide made wear() and arm() accept only 1 arg,
//           either a string or an object.

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#include <commands.h>
#include <config.h>
#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <move.h>
#include <money.h>
#include <priv.h>
#include <uid.h>
#include <logs.h>
#include <body.h>
#include <messages.h>

#define ROLL_STAT random(4) + random(4) + random(4) + 9
#define HP_ROLL random(5) + 4

object tmp ;
static int speed, hb_status;
inherit LIVING ;

int environment_check();
void wear(string arm, string arm2);
void arm(string wep, string wep2) ;
void spell_cast (string spell, int chance) ;
void move_around() ;
void monster_chat();
void unwield_weapon(object weapon) ;
void unequip_armor(object armor) ;
varargs private void execute_attack(int hit_mod, int dam_mod) ;
static int create_ghost();
static void die();

mapping alias ;

//  Setup basic and command catch systems

void basic_commands() {
    add_action("quit", "quit");
}

static void init_commands() {
    string path;

    add_action( "cmd_hook", "", 1 );

    if(link_data("wizard")) {
	enable_wizard();
	path = NEW_WIZ_PATH;
    }

    else path = USER_CMDS;

    set("PATH", path, MASTER_ONLY);
}

//  This function resets the monster's living_name after a user 
//  shells out of the monster body.

void reset_monster() {
    if(!interactive(this_object())) {
	set_living_name( query("name") );
	seteuid(getuid(this_object()));
	link = 0;
    }
}

void clear_monster() { if(geteuid(previous_object()) == ROOT_UID) seteuid(0); }


string process_input (string arg) {
    arg = do_alias(arg) ;
    return arg ;
}

//   Setup standard user command hook system.  This system interfaces
//   with the cmd bin system, the environment's exits, and feeling entries.

nomask static int cmd_hook(string cmd) {
    string file;
    string verb;

    verb = query_verb();

    if (environment() && environment()->valid_exit(verb)) {
	verb = "go";
	cmd = query_verb();
    }

    file = (string)CMD_D->find_cmd(verb, explode(query("PATH"), ":"));

    if (file && file != "")
	return (int)call_other(file, "cmd_" + verb, cmd);

    if (environment() && environment()->query("quiet")) return 0 ;
    return (int)EMOTE_D->parse(verb, cmd);
}

/*
 * Move the player to another room. Give the appropriate
 * message to on-lookers.
 * The optional message describes the message to give when the player
 * leaves.
 * 02 Jan 97 - Cyanide updated to support new MIN format.
 */
varargs int move_player(mixed dest, string message, string dir) {
    string dirfrom;
    object prev, *stuff;
    int res, i, I;
    mapping Exits;

    prev = environment( this_object() );
    if ( res = move(dest) != MOVE_OK ) {
	message(MSG_INFO, "You remain where you are.\n", this_player());
	return res;
    }

    if (environment() && wizardp(this_object()) && query("display_path"))
	message(MSG_LOOK, sprintf("[%s]\n", file_name(environment())),
	  this_object());

    if (message == "SNEAK") {
	set_temp("force_to_look", 1);
	command("look");
	set_temp("force_to_look", 0);
	return 0;
    }

    if (!query("invisible")) {
	Exits = environment()->query("exits");

	I = member_array((file_name(prev)+".c"), values(Exits));
	if (I!=-1) 
	    dirfrom = keys(Exits)[I];
	else
	    dirfrom = "somewhere";

	if (message == 0 || message == "") {

	    if (dir && dir != "") {
		message(MSG_MOVEMENT, (string)query_mout(dir) + "\n",
		  prev, this_object());
		message(MSG_MOVEMENT, (string)query_min(dirfrom) + "\n",
		  environment(), this_object());
	    } else {
		message(MSG_MOVEMENT, (string)query_mmout() + "\n",
		  prev, this_object());
		message(MSG_MOVEMENT, (string)query_mmin() + "\n",
		  environment(), this_object());
	    }
	} else {
	    message(MSG_MOVEMENT, message + "\n", prev, this_object());
	    message(MSG_MOVEMENT, (string)query_min(dirfrom) + "\n", environment(),
	      this_object());
	}
    }

    set_temp ("force_to_look", 1);
    command("look");
    set_temp("force_to_look", 0);


    /*
     * Follow/track mudlib support
    */
    if (!query("no_follow") && environment() != prev && prev){
	stuff = all_inventory(prev);
	for(i=0;i<(sizeof(stuff));i++){
	    stuff[i]->follow_other(this_object(), environment(), dir);
	}
    }
    return 0;
}

int clean_up_attackers() {  
    mixed *attackers_tmp;
    int i;
    attackers_tmp = ({});
    for (i=0; i < sizeof(attackers); i++) {

	// If he's YOU - come to your senses.
	if (attackers[i] == this_object() )
	    continue;

	// If he's dead, then forget about him entirely.
	if (attackers[i] == 0 || !living(attackers[i]))
	{
	    continue;
	}
	// If he's not here, then we consider two cases.
	if (environment(attackers[i]) != environment(this_player()))
	{
	    // If this is a monster who is not forgetful, then add this attacker to the
	    // will_attack, the list of objects to be attacked on sight.
	    if (!query("forgetful")) {
		if (!will_attack) will_attack = ({ attackers[i] }) ; else
		    will_attack += ({ attackers[i] }) ;
	    }
	    // If a forgetful monster, then forget about him.
	    continue ;
	}
	// If he's a ghost, we've done enough to him already :)
	if ((int)attackers[i]->query("ghost")) continue ;
	// If we get this far, then we still want to be attacking him
	attackers_tmp += ({ attackers[i] });
    }
    // Copy the tmp list over to the attackers list.
    attackers = attackers_tmp;
    if (sizeof(attackers_tmp) == 0)
	any_attack = 0;
    return any_attack;
}

//  This function filters an array returning only living objects.

int filter_listening(object obj) {
    if(obj == attackers[0] || obj == this_object())  return 0;
    return living(obj); }


// Valid_protect was the Holy Grail of protector errors.
// You may worship Cyanide, 5 Nov 97, who converted all strings to
// objects.

int valid_protect (object foo) {
    if (!foo) return 0 ;
    if (environment(foo)!=environment(this_object())) return 0 ;
    if ((int)foo->query("hit_points")<0) return 0 ;
    if (foo == this_object()) return 0 ;
    return 1 ;
}


//	If the monster body is inhabited by a user, give the
//	monster's living hash table name as that of the user.

varargs void init_setup(int reconnect) {

    if(!query_link())  return 0;

    set_heart_beat(1);
    seteuid(getuid(this_object()));
    set_living_name( link_data("name") );

    basic_commands();
    init_commands();

}

void create() {

    // Monsters need euid set so that they can clone corpses if they die.

    seteuid(getuid()) ;

    // no default aliases.

    alias = ([ ]);

    set("npc", 1, LOCKED);

    // Monsters default to the same size and carrying ability as humans. You
    // might want to change this in non-humanoid monsters.

    set("autosave", 500);
    set("volume", 500);
    set("max_vol", 500) ;
    set("capacity", 5000);
    set("max_cap", 5000) ;
    set("mass", "@@query_mass");
    set("time_to_heal",10) ;
    set("short", "@@query_short");
    set("vision", "@@query_vision");
    set("gender", "neuter");
    set("size", 6);
    set("SIZE", 6);
    set("resist_type", ([]) );
    enable_commands();

    set ("languages", ([ "common" : 100 ]) ) ;
    set_heart_beat(1);
    set ("base_ac", 10);
    set ("armor_class", 10);
    set ("PATH", "/cmds/std") ;
    basic_commands() ;
    init_commands() ;
}

void remove() {
    mixed *inv;
    int loop;

    inv = all_inventory(this_object());
    for(loop=0; loop<sizeof(inv); loop++)
	if(inv[loop]->query("prevent_drop"))
	    inv[loop]->remove();

	//   CMWHO_D->remove_user(this_object());
    if (link) link->remove();
    living::remove();
}

int quit(string str) {
    object ob;
    int i, j;

    if(str) {
	notify_fail("Quit what?\n");
	return 0; }

#ifdef LOGOUT_MSG
    tell_object(this_object(), LOGOUT_MSG);
#endif

#ifdef QUIT_LOG
    if(this_object() && interactive(this_object()))
	log_file(QUIT_LOG, link_data("cap_name") + ": Monster quit from " +
	  query_ip_name(this_object()) + " [" +
	  extract(ctime(time()), 4, 15) + "]\n");
#endif

    //   If the connection object is somehow missing ... 
    //	just remove the monster 

    if(!query_link()) {
	if(interactive(this_object()))  remove();
	reset_monster();
	return 1; }

    ob = new(OBJECT);			// Temporary body

    query_link()->set("tmp_body", ob);
    query_link()->switch_body();
    ob->remove();

    query_link()->remove();
    reset_monster();

    return 1; }

void heart_beat() {

    // If we're chasing someone, better go after him.

    if (query("in_pursuit")) {
	command("go "+query("in_pursuit")) ;
	if (present((object)query("pursued"),environment(this_object()))) {
	    tell_object((object)query("pursued"),
	      this_object()->query("cap_name")+" attacks you!\n") ;
	    query("pursued")->kill_ob(this_object()) ;
	}
	delete ("in_pursuit") ;
	delete ("pursued") ;
    }

    // if((int)query("hit_points") < 0) die();

    continue_attack();

    unblock_attack();
    move_around() ;
    if(random(100)+1 < query("chat_chance"))  monster_chat();

    // heal_up();

    //  If no-one is around and fully healed, shut down the heartbeat

    if(!environment_check() && query("hit_points") == query("max_hp")) {

	if(query("max_sp") && query("max_sp") != query("spell_points"))
	    return;

	// If we're whanging on someone, best not to shut it down... :)

	if (sizeof(attackers) || query("following")) return ;

	set_heart_beat(0);  hb_status = 0;  
    } 
}

//  This function allows monsters to talk or give environmental sounds.

void monster_chat() {
    mixed *chats;

    if(attackers && sizeof(attackers))  chats = query("att_chat_output");
    else  chats = query("chat_output");

    if(!chats || !sizeof(chats))  return ;

    if(environment())
	tell_room(environment(), chats[ random(sizeof(chats)) ]);

    return; }


// Let's get rid of this somehow.
void set_name (string str) {
    if (!str)  return;
    set ("name", str) ;
    set ("cap_name", capitalize(str)) ;
    set_living_name(str) ;
}


// This is the function called when the poor thing dies. It has been changed ALOT
// since TMI first did it.

static void die() {
    object killer, ghost, corpse, coins, *stuff;
    mapping ammo ;
    string *names, leader ;
    int i, res, totcoins, xpv ;

    killer = query("last_attacker");
    if (!killer)  killer = previous_object();

    init_attack() ;

    // we'll see if this gets rid of multi corpsing

    //killer->mod_morals(query_morals(1));
    //killer->mod_ethics(query_ethics(1));

    if(query("alt_corpse")){
	corpse = clone_object(query("alt_corpse"));
    } else {
	corpse = clone_object(STD_CORPSE);
    }

    if (query("cloned_by"))
	corpse->set("cloned_by", query("cloned_by"));
    corpse->set_name(query("cap_name")) ;
    corpse->set("filename", file_name(this_object()) );
    corpse->set("level", (query("level")));
    corpse->set("killer", killer->query("cap_name"));
    corpse->set("old_id", query("id") );

    i = query("mass") ;
    if (i>0) corpse->set("mass", i) ;

    i = query("capacity");
    if (i>0) corpse ->set("capacity", i) ;

    i = query("max_cap");
    if (i>0) corpse ->set("max_cap", i) ;

    corpse->move(environment(this_object()));
    // Now give the corpse all the user's stuff.

    stuff = all_inventory(this_object());

    for (i = ((sizeof(stuff))-1); i >= 0; i--) {
	if (stuff[i]->query("dest_at_die")) {
	    stuff[i]->remove();
	    continue;
	}
	if (!stuff[i]->query("prevent_drop") && !stuff[i]->query_auto_load())
	    stuff[i]->move(corpse);

	if (query("cloned_by"))
	    stuff[i]->set("cloned_by", query("cloned_by"),
	      LOCKED);

	stuff[i]->delete("native_object");
    }

    if (total_wealth()) {
	coins = clone_object(COINS);      // Coins fixed by 
	coins->set_number(total_wealth()); // Cyanide 26 Jun 97
	if (coins)
	    coins->move(corpse);
    }
    set ("wealth", 0);

    // Drop all ammo into the corpse.
    ammo = TP->query("ammo");
    if (!ammo) ammo = ([]);
    names = keys(ammo);
    for (i=0; i<sizeof(names); i++) {
	res = ammo[names[i]];
	if (res > 0) {
	    coins = clone_object(AMMO);
	    coins->set_type(names[i]);
	    coins->set_number(res);
	    coins->move(corpse);
	}
    }

    //  Set the last_kill variable ... file_name and short of this_object

    if(killer)
	killer->set("last_kill", ({ file_name(this_object()), query("short"),
	  time() }));

    // Announce the sad facts of life and non-life.

    write("You have died.\n");
    say(query("cap_name") + " staggers and falls to the ground ... dead.\n",
      ({ this_player() }) );

    //ilz puts in xp now
    // Cyanide added the party sharing stuff 13 Oct 97.
    //Ilz tries to cut down on low level sweep killing (4/12/98)

    if(killer && living(killer)) {
	// Reusing vars to save on mem. 
	// You weren't using that, were you?  -Cyanide

	i = query("xpv");
	leader = (string)killer->query("leader");

	if (leader){
	    ghost = find_player(leader);
	}
	if (ghost) { 
	    if (attackers && will_attack) attackers += will_attack;
	    else attackers = ({});
	    DEBUG("Leader = "+ghost->query("cap_name"));
	    PARTY_D->share_exp(ghost, i, attackers);
	} else {
	    if (killer->query("xp_penalty"))
		i = ((100 - (killer->query("xp_penalty")))* i)/100;
	    killer->add("kills", 1);

	    /*
			    //comment out form here..
			    xpv = (killer->query_level());
			    if (xpv > 40) xpv = 40;
			    xpv = ((this_object()->query_level()) - xpv);
			    xpv += 20;
	    if (xpv < 10) (i = (xpv * (i / 10)));
			    if (i < 1) i = 1;
			    // to here if the xp hack doesnt work
	    */

	    tell_object(killer, "You gain "+i+" experience.\n");
	    killer->add_experience(i);

	    ammo = (mapping)killer->query("best_kill");
	    if (ammo){
		if (i > values(ammo)[0]) {
		    killer->set("best_kill", ([ query("short") : i ]) );
		    tell_object(killer, "-= You have a new best kill! =-\n");
		} 
	    } else {
		tell_object(killer, "-= You have a new best kill! =-\n");
		killer->set("best_kill", ([ query("short") : i ]) );
	    }   
	}

	if (interactive(this_object())) {
	    set("dying", 1);
	    set("hit_points", 1);

	    // Move the poor sod...

	    this_object()->move(DEATH_ROOM);
	}

	//	Delay the remove call with a call_out to ensure all the 
	//	housekeeping from above is complete.
    }
    call_out("remove", 0);


}
// These are the hooks for aggressive and killer monsters.
// If a monster turns on the "aggressive" property, then if they receive
// a message of the form "Foo enters" then they attack Foo. This is done
// in receive_messages. Players can get past these monsters by sneaking
// into the room or being invisible. Also, they don't attack if they enter
// the player's environment, only if the player enters theirs. Monsters
// which turn on the "killer" property will attack any player that triggers
// the monster's init. It can't be fooled by invis or sneaking, and it will
// attack you if it moves into your room. Moving killer monsters can be
// pretty nasty things.

void relay_message(string Class, string str) {

    string name ;
    string direction ;
    object victim ;

    if (str && (sscanf(str,"%s enters.",name)==1 ||
	sscanf (str, "Suddenly %s appears as if out of thin air.",name)==1)) {
	name = lower_case(name) ;
	victim = present(name,environment(this_object())) ;
	if (!victim) return ;


    }
    if (query("pursuing") && str && sscanf(str,"%s leaves %s.",name,direction)==2) {
	name = lower_case(name) ;
	victim = find_living(name) ;
	if (attackers && member_array(victim,attackers)>-1) {
	    set ("in_pursuit", direction) ;
	    set ("pursued", victim) ;
	}
    }

}

void init() {
    object victim;
    //  If object is not a monster and is visible (or invis -Ilz)...think about attacking.
    victim = this_player() ;
    if(!this_player()->query("npc") && !this_player()->query("ghost")) {

	if(will_attack && member_array(this_player(), will_attack) != -1) {
	    write(capitalize(query("name")) + " attacks you as you return!\n");
	    will_attack -= ({ this_player() });
	    kill_ob( this_player() );
	    TO->continue_attack();
	}
    }
    //  If heartbeat is turned off ... turn it back on.
    if(query("aggressive") && !victim->query("ghost")) {

	write("As you enter, " + capitalize(query("name")) + " suddenly " +
	  "attacks you!\n");
	kill_ob( this_player() );
    }

    if(!hb_status) {  hb_status = 1;  set_heart_beat(1);  }

}

// This lets a pursuing monster chase you. It's call_out'd from
// relay_message.


int query_monster() { return 1; }

int query_npc() { return 1; }

int query_hb_status() {  return hb_status;  }

int move_counter = 0, patrol_step = 0;

void move_around() {
    mapping doors,exits, tmp, patrol ;
    string foo,tstr ;
    string *nogos ;
    string *dirs ;
    int i, speed ;

    if (query("summoned") && !query("summoner")) {
	message(MSG_MOVEMENT, wrap("The magics binding "+query("cap_name")
	    +" to this plane unravel, and "+subjective(query("gender"))+
	    " is returned home."), environment(TO), ({}) );
	remove();
    }

    if (!query("moving") && !query("following") 
      && !query("patrol")) 
	return;

    // If in combat, we stay put!
    // (Unless following somebody)
    if (sizeof(attackers) && !query("following")) return;

    speed = (int)query("speed");
    if (!speed) speed = 10;

    // Following creatures have more motivation.
    if (query("following")) {
	if (speed > 12) speed = 12;
	speed /= 2;
    }

    if (move_counter>=speed) {    // Do move stuff... 
	move_counter = -1;

	// Check and see if we're following anybody... again.
	if (query("following")) {
	    object ob = environment(this_object());
	    if ( ob == environment(query("following")) )
		return;

	    if (  move(environment(query("following")))==MOVE_OK ) {
		message(MSG_MOVEMENT, query("cap_name")+" follows "+
		  possessive(query("gender"))+ " master.\n", ob);

		ob = environment(this_object());

		foo = query("cap_name") + " enters following "+
		possessive(query("gender"))+ " master.\n";

		message(MSG_MOVEMENT, foo, ob);

		move_counter++;
		return;
	    }
	}

	// If we have no environment, then stop moving around. Done for two
	// reasons. First, there's nowhere to go anyway, so save CPU. Second,
	// this stops the callout loop in master copies of objects.
	// We also shut it down if there's no exits: same logic.
	if (!environment(this_object()) ||
	  !environment(this_object())->query("exits")) {
	    return ;
	}

	// If we have a patrol pattern to follow, get the direction from
	// that. If not, pick a direction at random.

	exits = environment(this_object())->query("exits") ;
	patrol = this_object()->query("patrol") ;
	if (sizeof(patrol)) {
	    foo = patrol[patrol_step] ;
	} else {
	    dirs = keys(exits) ;
	    foo = dirs[random(sizeof(dirs))] ;
	    nogos = query("forbidden_rooms") ;
	    if (!exits[foo]) return;
	    if(exits[foo]->query("forbidden")) return;
	    if (nogos && member_array(exits[foo],nogos)!=-1)
		return ;
	}

	doors = environment(this_object())->query("doors") ;
	if (doors && sizeof(doors) && doors[foo] &&
	  doors[foo]["status"]!="open") {
	    command("open "+foo+" door") ;
	    return ;
	}

	tmp = environment(this_object())->query("exit_msg");
	if(tmp && mapp(tmp) && tmp[foo]) {
	    tstr = replace_string(tmp[foo], "$N", 
	      (string)this_object()->query("cap_name"));
	    move_player(exits[foo], tstr);
	} else {
	    tstr = query_mout(foo);
	    move_player(exits[foo], tstr);
	}
	if (sizeof(patrol)) {
	    patrol_step++;
	    if (patrol_step==sizeof(patrol)) 
		patrol_step=0 ;
	}

    }  // if (move_counter>=speed)

    // Finally, increment the move counter. 
    move_counter++;
}

// We don't use this anymore.
void spell_cast (string spell, int chance) {
    set ("spellcaster",1) ;
    set ("spell_to_cast",spell) ;
    set ("spell_chance",chance) ;
}

void wield_weapon (object weapon) {
    string str ;
    if(!weapon->query("weapon")) return;
    str = weapon->query("id") ;
    command("wield "+str);
}

void equip_armor (object armor) {
    string type ;
    object foo ;
    if(!armor->query("armor")) return;
    type = armor->query("type") ;
    foo = query("armor/"+type) ;
    if (foo) unequip_armor(foo) ;
    set ("armor/"+type,(int)armor->query("armor")) ;
    armor->set("equipped",1) ;
    calc_armor_class() ;
}

void equip(string *list){
    int i;
    object ob;
    if(!list || !pointerp(list)) return;
    i = sizeof(list);
    while(i--)
    {
	ob = clone_object(list[i]);
	if(ob->query("weapon"))
	{
	    equip_armor(ob);
	}
	else
	{
	    equip_armor(ob);
	}
    }
    return ;
}
void unwield_weapon (object weapon) {

    string str ;

    set ("weapon1", 0) ;
    weapon->unwield() ;
    //	str = weapon->query("unwield_func") ;
    //       if (str) call_other(weapon,str) ;
}

void unequip_armor (object armor) {

    string type ;

    type = armor->query("type") ;
    delete ("armor/"+type) ;
    armor->unequip() ;
    calc_armor_class() ;
}

//  This function checks to see if there are any players present in 
//  the monsters room, so heartbeat can be turned off periodically.

int environment_check() {

    if(interactive(this_object()))  return 1;

    if(environment())
	return sizeof(filter_array(all_inventory(environment()), "filter_env",
	    this_object()));  
    return 0; }

static int filter_env(object obj) {
    return (interactive(obj) && visible(obj, this_object())); }


// This func sets all the level-related stuff in monsters, and
// rools any stats necessary.
// 30 Jun 97 Ilzarion added con boni.
// 02 Jul 97 Cyanide repaired the CPU pain Ilz put in. A loop full
//    of like 10 "if" statements HURTS.

void set_level (int level) {
    int i, hp;

    if (query("size") > 0) {
	if (!query("stat/strength")) {
	    set("stat/strength", (ROLL_STAT*(int)query("size"))/6);
	}
    } else {
	if (!query("stat/strength")) set("stat/strength", ROLL_STAT);
    }
    if (!query("stat/dexterity")) set("stat/dexterity", ROLL_STAT);
    if (!query("stat/constitution")) set("stat/constitution", 12);
    if (!query("stat/intelligence")) set("stat/intelligence", ROLL_STAT);
    if (!query("stat/wisdom")) set("stat/wisdom", ROLL_STAT);
    if (!query("stat/charisma")) set("stat/charisma", ROLL_STAT);

    set("base_stat/dexterity", query("stat/dexterity"));
    set("base_stat/strength", query("stat/strength"));
    set("base_stat/constitution", query("stat/constitution"));
    set("base_stat/wisdom", query("stat/wisdom"));
    set("base_stat/intelligence", query("stat/intelligence"));
    set("base_stat/charisma", query("stat/charisma"));

    set ("level", level);
    set("enchantment", (level/4));
    if (level>10) level = level + ((level - 10) * 3);
    hp = 0;
    //for (i=0;i<level;i++) hp += HP_ROLL;
    hp = 21 * level;

    // Increase the base hit_points by a % equal to the
    // monster's level * 5. Slows down combat. 
    // Cyanide, 22 Apr 98
    //lets try 3 % , 5 is a bit much.
    i = (level * 3) + 100;
    hp = (i * hp)/100;

    hp += ((PROPERTY_D->query_con_hp_bonus ( TO )) * level );
    set ("max_hp", hp);
    set ("hit_points", hp);
    set("thac0", "@@query_thac0");
    PROPERTY_D->calc_xpv(this_object());
}

varargs int query_level( string blah ) {
    return query("level");
}

// For easily arming a monster with a weapon.
varargs void arm(mixed wep, string wep2) {
    int lvl_int;
    string wep_type;
    object thang;

    if (!wep) return ;

    if (stringp(wep)) {
	// Temporary storage.
	wep_type = wep;

	// If they didn't put the .c at the end of the file..
	sscanf(wep_type, "%s.c", wep_type) ;

	// It's there now.
	wep_type += ".c" ;
	if (file_exists(wep_type)) 
	    thang = clone_object(wep_type);
    }
    if (objectp(wep)) thang = wep;

    if (thang) {
	lvl_int = TO->query_level() / 4;
	if (lvl_int < 1) lvl_int = 1;
	if (lvl_int > 5) lvl_int = 5;
	thang->move(TO);
	wep_type = thang->query("weapon_type");
	if (!TO->query_skill(wep_type))
	    set_skill(wep_type, lvl_int, "strength");

	command("wield "+(thang->query("id"))[0]+" SILENT") ;
    }
    return ;
}

varargs void wear(mixed arm, string arm2) {
    object thang;
    string str;

    if (!arm) return ;

    if (stringp(arm)) {
	// Temporary storage.
	str = arm;

	// If they didn't put the .c at the end of the file..
	sscanf(str, "%s.c", str) ;

	// It's there now.
	str += ".c" ;
	if (file_exists(str)) 
	    thang = clone_object(str);
    }
    if (objectp(arm)) thang = arm;

    if (thang) {
	thang->move(TO);
	command("equip "+(thang->query("id"))[0]+" SILENT") ;
    }
    return ;
} 

string query_title() {
    return capitalize((string)query("short"));
}
/* EOF */
