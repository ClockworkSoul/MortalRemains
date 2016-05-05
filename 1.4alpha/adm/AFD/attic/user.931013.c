// File: /std/user.c
// The user body is from the TMI-2 lib. Part of the bodies project and
// implemented by Watcher@TMI-2 and Mobydick@TMI-2. The code contained
// in this object is heavily based on code found in the original user.c
//
// The relevant code headers follow:
// Original Authors: Sulam and Buddha @ The Mud Institute
// Many other people have added to this as well.
// This file has a long revision history dating back to the hideous
// mudlib.n and is now probably not at all the same.
// This file is part of the TMI distribution mudlib.
// Please keep this header with any code within.
 
#include <config.h>
#include <login.h>
#include <commands.h>
#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <flock.h>
#include <move.h>
#include <money.h>
#include <priv.h>
#include <uid.h>
// Some files are inherited by including user.h.
#include <user.h>
#include <user2.h>
#include <logs.h>
#include <body.h>
// This is only needed for consistency_check.
#include <channels.h>
 
inherit LIVING ;

// This is probably only a local hack.

 
static void complete_setup (string str) ;
static void die();
static int create_ghost();
int coins_carried();
int query_permission(string prop);
void init_setup();
void destroy_autoload_obj();
varargs private void execute_attack(int hit_mod, int dam_mod) ;
 
//  Setup basic and command catch systems
 
void basic_commands() {
   add_action("quit", "quit");
}

static void init_commands() {
   string path;

   add_action( "cmd_hook", "", 1 );
 
   path = query("PATH");
 
   if(!path) {
      if( wizardp(this_object()) )
         path = NEW_WIZ_PATH;
      else
         path = USER_CMDS;
 
      set("PATH", path, MASTER_ONLY);
   }
}
 
//   Setup standard user command hook system.  This system interfaces
//   with the cmd bin system, the environment's exits, and feeling entries.

nomask static int cmd_hook(string cmd) {
   string file;
   string verb;
   int foo ;
   mapping before, after ;

   verb = query_verb();
 
   if (environment() && environment()->valid_exit(verb)) {
      verb = "go";
      cmd = query_verb();
   }

   file = (string)CMD_D->find_cmd(verb, explode(query("PATH"), ":"));
 
   if(file && file != "")
{
#ifdef PROFILING
   before = rusage() ;
#endif
      foo = (int)call_other(file, "cmd_" + verb, cmd);
 
#ifdef PROFILING
        after = rusage() ;
    	"/adm/daemons/profile"->log_cmd(verb,before,after) ;
#endif

	return foo ;
}

   if (environment() && environment()->query("quiet")) return 0 ;
#ifdef PROFILING
	before = rusage() ;
#endif
   foo = (int)EMOTE_D->parse(verb, cmd);
    if (foo) {
#ifdef PROFILING
    	after = rusage() ;
    	"/adm/daemons/profile"->log_cmd(verb,before,after) ;
#endif
	return foo ;
     }
#ifdef PROFILING
	before = rusage();
#endif
    foo = (int) CHANNELS_D -> parse_channel( verb, cmd );
#ifdef PROFILING
     if( foo ) {
	    after = rsuage();
	      "/adm/daemons/profile" -> log_cmd( verb, before, after );
     }
#endif
    return foo;
}

 
//	This function protects the object from being shadowed for 
//	certain secure functions.

nomask int query_prevent_shadow(object ob) {
   mixed *protect;
   int loop;
 
   protect = ({ "catch_tell", "receive_message", "do_alias", "do_history",
		"do_nickname", "receive_snoop" });
 
   for(loop=0; loop<sizeof(protect); loop++)
     if(function_exists(protect[loop], ob))  return 1;

return 0; }
 
/*
* Move the player to another room. Give the appropriate
* message to on-lookers.
* The optional message describes the message to give when the player
* leaves.
*/
 
varargs int move_player(mixed dest, string message, string dir) {
   object prev;
   int res;
   
   prev = environment( this_object() );
   if( res = move(dest) != MOVE_OK ) {
      write("You remain where you are.\n");
      return res;
   }
 
   if(environment() && wizardp(this_object()) && query("display_path"))
   tell_object(this_object(),"[" + file_name(environment()) + "]\n");
 
   if(message == "SNEAK") {
     set_temp("force_to_look", 1);
     command("look");
     set_temp("force_to_look", 0);
   return 0; } 
 
   if(!query("invisible")) {

     if(message == 0 || message == "") {
 
	if(dir && dir != "") {
 	   tell_room(prev, (string)this_object()->query_mout(dir) + "\n",
			({ this_object() }));
	   say((string)this_object()->query_min() + "\n", ({ this_object() }));
	} else {
	   tell_room(prev, (string)this_object()->query_mmout() + "\n",
		 	({ this_object() }));
	   say((string)this_object()->query_mmin() + "\n", ({ this_object() }));
	}
     } else {
	tell_room(prev, message + "\n", ({ this_object() }));
	say((string)this_object()->query_min() + "\n", ({ this_object() }));
     }
   }
 
    set_temp ("force_to_look", 1) ;
    command("look") ;
    set_temp("force_to_look", 0) ;

 
   //	Follow/track mudlib support
 
   if(!this_object()->query("no_follow") && environment() != prev && prev)
     all_inventory(prev)->follow_other(this_object(), environment(), dir);
 
   return 0;
}

private int clean_up_attackers() {
   mixed *attackers_tmp;
   int i;
 
   attackers_tmp = ({});
 
   for (i=0; i < sizeof(attackers); i++) {
	// If he's dead, then forget about him entirely.
	if (attackers[i] == 0 || !living(attackers[i]))
	   continue;
 
	// If he's not here, then forget about him.
	if (environment(attackers[i]) != environment(this_player()))
	    continue ;
 
	// If he's a ghost, we've done enough to him already :)
	if ((int)attackers[i]->query_ghost()==1) continue ;
 
	// If we get this far, then we still want to be attacking him
      	attackers_tmp += ({ attackers[i] });
   }
 
	// Copy the tmp list over to the attackers list.
   	attackers = attackers_tmp;
 
   if (sizeof(attackers_tmp) == 0)
      any_attack = 0;
 
return any_attack; }

// Continue_attack is called from heart_beat..
// here is where we can try to see if we're dead or in combat.

void continue_attack() {
 
	// Check if this object has just died. if so, do the death stuff.
   	if (query("hit_points") < 0) {  die();  return ;  }
 
	// If there's no one to attack, then we are finished.
   	if (!any_attack) return;
 
	// Call the clean_up_attackers function to see who's left. If it
	// returns 0, then there's no one left.
   	if (clean_up_attackers() == 0) {
      	write("The combat is over.\n"); /* No attackers in the room */
      	return;
   	}
 
	// Check to see if the player is doing something that prevents
	// him from making an attack.
   	if (query("stop_attack")>0) {
	write ("You are too busy to make an attack!\n") ;
   	return ;
   	}
 
	// Check to see if we're under wimpy, and if so, run away.
	if(query("hit_points")*100/query("max_hp") <
	   this_player()->query("wimpy")) {
       	run_away();
       	return;
   	}
   
      	execute_attack();
}

// This is the big, ugly CPU hogging function where the combat actually
// takes place.

static int loop, noise;
 
varargs void execute_attack (int hit_mod, int dam_mod) {

	int att_sk, def_sk, str, dex, ac, wc, hit_chance ;
	string name, verb1, verb2, vname, damstr, damstr2, wepstr, *verbs;
	mixed *contents;
	object *prots ;
	object weapon ;
	int old_inv ;
	string victim ;
	int *damrange ;

// Check to see if primary target is dead, if so move to the next attack
// in the attackers queue. If the attackers queue is empty, stop attack call.

  	if(attackers[0]->query("hit_points") < 0) {
	  attackers -= ({ attackers[0] });
	  if(!attackers || !sizeof(attackers))  return;
	}

// Is the target being protected? If so, find the alternate target.

        prots = attackers[0]->query("protectors") ;
        if (prots && sizeof(prots)>0) {
// Get rid of all ineligible protectors: dead or not present.
            prots = filter_array(prots,"valid_protect", this_object()) ;
// If there are eligible protectors, then move the protector to the top
// of the list, adding him if needed.
                if (sizeof(prots)) {
                        victim = prots[random(sizeof(prots))] ;
// re-using a variable to save memory - sorry bout that :(
                        weapon = find_player(victim) ;
                        ac = member_array(weapon,attackers) ;
                        if (ac>-1) {
                                attackers[ac]=attackers[0] ;
                                attackers[0]=weapon ;
                        } else {
                                attackers = ({ weapon }) + attackers ;
				weapon -> kill_ob(this_object()) ;
                        }
                }
        }
 
// hit_mod and dam_mod are modifiers that can be passed to the attack.
// The heartbeat doesn't add them but you can make special attacks by
// calling execute_attack directly. Be careful if you do so, you'll want
// to also call kill_ob to make sure a fight starts...
 
	if (!hit_mod) hit_mod=0 ;
	if (!dam_mod) dam_mod=0 ;
 
// Collect the various statistics needed to get the hit chance and damage.
 
        str = this_object()->query("stat/strength") ;
	dex = attackers[0] ->query("stat/dexterity") ;
	ac = attackers[0]->query("armor_class") ;
        weapon = this_object()->query("weapon1") ;
 
// If they don't have a weapon, they get their intrinsic combat skills.
	if (!weapon) {
// These are the numbers/strings for a unarmed user attack. They're hard-coded
// but you could equally well set them as properties in the user object. 
			wc = 2 ;
			dmin = 1 ;
			dmax = 3 ;
			verb1 = "swing at" ;
			verb2 = "swings at" ;
			wepstr = "fists" ;
			weapontype = "Blunt weapons" ;
	} else {
// If we get here, then the player has a weapon, and we query the weapon
// for its attack properties.
// Does he have a second weapon? If so, use it on 20% of attacks.
		if (query("weapon2") && random(5)==0) {
			weapon = query("weapon2") ;
		}
		wc = this_object()->query("attack_strength") ;
        	damrange = weapon->query("damage") ;
        	dmin = damrange[0] ;
        	dmax = damrange[1] ;
		verbs = allocate(2) ;
		verbs = weapon->get_verb() ;
		verb1 = verbs[0] ;
		verb2 = verbs[1] ;
		wepstr = (string)weapon->query("name") ;
		weapontype = capitalize(weapon->query("type")+" weapons") ;
	}
	name = query("cap_name") ;
	vname = attackers[0]->query("cap_name") ;

// Check the attacker's attack skill and the defenders skill(s).

// If a player, check his weapons skills. Otherwise, use the attack skill
// for a monster.
 
	att_sk = this_object()->query_skill(weapontype) ;
 
// Ditto for the defender.
	if (!(int)attackers[0]->query_monster()==1) {
		if (attackers[0]->query("armor/shield")) {
			def_sk = attackers[0]->query_skill("Shield defense") ;
		} else {
			def_sk = attackers[0]->query_skill("Parrying defense") ;
		}
	} else {
		def_sk = attackers[0]->query_skill("defense") ;
	}

// This is the combat formula.
// If you are using drunkenness, and want it to affect combat, then
// call query("drunk"), which goes 1-25, and subtract it from the
// hit chance.

	hit_chance = 30 + str + att_sk + 3*wc - dex - def_sk - 3*ac + hit_mod ;

// Attacking invisible creatures is really rather difficult.

	if ((int)attackers[0]->query("invisible")>0) hit_chance=hit_chance / 5 ;

// The hit chance is constrained to be between 2 and 98 percent.
 
	if (hit_chance<2) hit_chance = 2 ;
	if (hit_chance>98) hit_chance = 98 ;

// Improve the skills of the attacker and defender.

// The probability of the skill improving depends on the hit chance. If the
// hit chance is 0 or 100, the skill does not improve. If the hit chance is
// 50%, then the skill improves automatically. The closer the hit chance is
// to 50%, the more likely the skill is to improve. This rewards players for
// taking on monsters roughly equal in skill to themselves.

	skill_improve_prob = hit_chance * (100-hit_chance) / 25 ;
	if (random(100)<skill_improve_prob) {
		this_object()->improve_skill(weapontype,1) ;
	}
	if (random(100)<skill_improve_prob) {
		if (!attackers[0]->query_monster()) {
			if (attackers[0]->query("armor/shield")) {
				attackers[0]->improve_skill("Shield defense",1) ;
			} else 	{
				attackers[0]->improve_skill("Parrying defense",1) ;
			}
		}
	}

// Get a list of all in the room who are listening to the battle.
 
	contents = all_inventory(environment(this_object()));
	contents = filter_array(contents, "filter_listening", this_object());
 
// This is the damage formula.
// We have to calculate this first because we don't want to print messages
// of the form "You hit for zero damage." If the damage is less than zero,
// we print a "You miss" message regardless of the hit_chance roll.

	damage = random(dmax-dmin+1)+dmin+str/8-1+att_sk/10-def_sk/5+dam_mod ;

// Before we print any messages, we need to make ourselves visible.
// Otherwise the person we're attacking doesn't get the message. We
// become invisible again after the messages are printed.
// This is klugey but real real easy.

	old_inv = query("invisible") ;
	set ("invisible", 0) ;
// If positive damage, and the hit lands, then we do damage and print
// the appropriate damage messages.
 
	if (damage>0 && random(100)<hit_chance) {

		str = attackers[0]->query("hit_points") ;
		if(damage)  attackers[0]->receive_damage(damage);
		qs = objective((string)attackers[0]->query("gender")) ;
 
// We print different damage messages based on how much damage was done.
// You might want to make this system a little more interesting. Go nuts.
 
		switch (damage) {
			case 1: {
				damstr = "scratch "+qs+"." ;
				damstr2 = "scratches "+qs+"." ;
				break ;
			    }
			case 2..3 : {
				damstr = "do light damage." ;
				damstr2 = "does light damage." ;
				break ;
			    }
			case 4..6 : {
				damstr = "hit." ;
				damstr2 = "hits." ;
				break ;
			    }
			case 7..9 : {
				damstr = "deliver a solid blow." ;
				damstr2 = "delivers a solid blow." ;
				break ;
			    }
			case 10..15 : {
				damstr = "hit hard!" ;
				damstr2 = "hits hard!" ;
				break ;
			    }
			case 16..20 : {
				damstr = "inflict massive damage!" ;
				damstr2 = "inflicts massive damage!" ;
				break ;
			    }
			default : {
// Mobydick just ran out of ideas at this point.  :)
				damstr = "whomp "+qs+"!" ;
				damstr2 = "whomps "+qs+"!" ;
			}
		}


        // The routines below check to see if all the listeners really
        // want to hear how the battle is going (Watcher, 4/27/93).

        if(!(this_object()->query("noise_level") && damage < 2))
        write("You " + verb1 + " " + vname + " with your " +
              wepstr + " and " + damstr + "\n");

        for(loop=0; loop<sizeof(contents); loop++) {
          if(contents[loop])
                noise = (int)contents[loop]->query("noise_level");

          if(noise && (noise > 1 || (noise == 1 && damage < 2)))
                continue;

          tell_object(contents[loop],
            name + " " + verb2 + " " + vname + " with " +
            possessive(this_object()->query("gender")) + " " + wepstr +
            " and " + damstr2 + "\n");

        }

        if(attackers[0] &&
           !(attackers[0]->query("noise_level") && damage < 2))
        tell_object(attackers[0],
          name + " " + verb2 + " you with " +
          possessive(this_object()->query("gender")) + " " + wepstr +
          " and " + damstr2 + "\n");

        } else {

// If we got here, it means we missed the hit roll, or did zero damage.

        if(!this_object()->query("noise_level"))
          write("You " + verb1 + " " + vname + " with your " + wepstr +
                " but you miss.\n");

        for(loop=0; loop<sizeof(contents); loop++)
          if(contents[loop] && !contents[loop]->query("noise_level"))
          tell_object(contents[loop],
                name + " " + verb2 + " " + vname + " with " +
                possessive(this_object()->query("gender")) + " " + wepstr +
                " but misses.\n");

        if(attackers[0] && !attackers[0]->query("noise_level"))
          tell_object(attackers[0],
                name + " " + verb2 + " you with " +
                possessive(this_object()->query("gender")) + " " + wepstr +
                " but misses you.\n");
        }

// Restore the old invisibility setting.

	if (old_inv) set ("invisible", old_inv) ;

return; }

//  This function filters out the living objects who are listening
//  to the present battle.
 
int filter_listening(object obj) {
   if(obj == this_object() || obj == attackers[0])  return 0;
return living(obj); }

// This one filters dead or absent people from an array.

int valid_protect (string str) {

        object foo ;

        foo = find_player(str) ;
        if (!foo) return 0 ;
        if (environment(foo)!=environment(this_object())) {
                return 0 ;
        }
        if ((int)foo->query("hit_points")<0) return 0 ;
        return 1 ;
}
 

void create() {
 
  if(user_exists(getuid())) return;
 
   //	Until the user's name and id is set ... give it a temporary one.
 
   set("name", "noname", MASTER_ONLY);
   set("id", ({ "noname" }));

// We set EUID of 0 so that the login daemon can export the proper
// UID onto the player. If you are running without AUTO_SETEUID, then
// this has no effect, but under auto-EUID-setting it's important.
// Also it makes it mildly harder for people to get themselves into
// trouble by cloning user.c.

   seteuid(0) ;


   // there's some standard properties that need to be locked so that
   // Joe Random Wizard can't break security by setting them on people
   // who haven't used them yet.

   set("npc", 0, LOCKED);
   set("snoopable", 0, MASTER_ONLY);
   set("invisible", 0, MASTER_ONLY);
   set("short", "@@query_short");
   set("cap_name", capitalize(query("name")));
   set("title", "@@query_title", MASTER_ONLY);
   set("linkdead", "@@query_linkdead");
   set("age", 0, MASTER_ONLY);
   set("ghost", 0, MASTER_ONLY);
   set("shell", "none", MASTER_ONLY);
   set("user", 1, MASTER_ONLY);
   set("vision", "@@query_vision");
   set("harass", 0, OWNER_ONLY);
   alias = ([ ]);
 
   //	Complete the standard user attribute settings.
 
   set("volume", MAX_VOLUME);
   set("capacity", MAX_CAPACITY);
   set("mass", USER_MASS) ;
   set("bulk", USER_BULK) ;
   set ("time_to_heal", 10) ;
   set("short", "@@query_short");
   set("channels", "", MASTER_ONLY);
   enable_commands();
}

void remove() {
   string euid;
   mixed *inv;
   int loop;
 
   if(previous_object()) {
      euid = geteuid(previous_object());
      if( (euid != ROOT_UID) && 
          (euid != geteuid(this_object())) &&
          !member_group(euid, "admin")       ) {
         write("You may not remove other players.\n");
         return;
      }
   }
   free_locks(this_object());

   save_data();
   destroy_autoload_obj();
 
   inv = all_inventory(this_object());
   for(loop=0; loop<sizeof(inv); loop++)
     if(inv[loop]->query("prevent_drop"))
	inv[loop]->remove();
 
   this_object()->tsh_cleanup();
   CMWHO_D->remove_user(this_object());
   if (link) link->remove();
   living::remove();
}
 
static int in_de_quit_script;

int quit(string str) {
   object *stuff, *inv;
   int i, j;

   if(str) {
   notify_fail("Quit what?\n");
   return 0; }

// If the #define is on, then save their location for starting next time.

#ifdef REAPPEAR_AT_QUIT
    if (environment(this_player())) {
        set ("start_location", file_name(environment(this_player()))) ;
    } else {
	set ("start_location", START) ;
    }
#endif

   //   Free any outstanding file locks.

    free_locks(this_object()) ;
 
   //	Get rid of any party memberships.
 
//  check_team() ;
    PARTY_D->check_party(this_object()) ;
 
   if( wizardp( this_object() ) )   {
      string quit_script; // Pallando 93-02-11

      quit_script = user_path( query( "name" ) ) + ".quit";
      if( file_size( quit_script ) > 0 )
      {
          if (in_de_quit_script++)
              write("Oi, stupid! Don't put `quit' in your ~/.quit file\n");
          else
               call_other( this_object(), "tsh", quit_script );
           in_de_quit_script = 0;
       }
   }

   // If the "harass" logging is still on, then turn it off.
   
   if (query("harass") > 0 ) {
	set("harass", 0);
	write("Harass Log turned off.\n");
   }
 
#ifdef LOGOUT_MSG
   if(previous_object() == this_object() && this_player())
	write( LOGOUT_MSG );
#endif

   // If this is an invisible wizard, we let the invisibility stay on: but
   // if it's a player who cast the invisibility spell, then we want him
   // to be visible when he reappears.

   if(!wizardp(this_object()))	set("invis", 0);

   if (link) {
	link->set("last_on", time());
	link->set("ip", query_ip_name(this_object())) ;
   }
 
#ifdef QUIT_LOG
   log_file(QUIT_LOG, query("cap_name") + ": quit from " +
	    query_ip_name(this_object()) + " [" +
	    extract(ctime(time()), 4, 15) + "]\n");
#endif
  
   //   First save the user's personal data.

   save_data();

   //   Then destroy autoloading inventory.

   destroy_autoload_obj();

   //   Now drop everything droppable on the user.

   inv = all_inventory( this_object() );
   inv = filter_array(inv, "inventory_check", this_object());

   if(inv && sizeof(inv))  command("drop all");
 
   //	Announce the departure of the user.

   if(this_object() && visible(this_object()))
   say(query("cap_name") + " left the game.\n");
 
   if(this_object() && interactive(this_object()))
   ANNOUNCE->announce_user(this_object(), 1);
 
   //	Clean up a few loose ends before shutting down the user.
 
   this_object()->tsh_cleanup();
   CMWHO_D->remove_user(this_object());
   if (link) link->remove();
   living::remove();
 
   return 1; 
}


// This function determines if the user has anything droppable 
// when they quit the mud.

static int inventory_check(object obj) {
  if(obj->query_auto_load()) return 0;
  if(!obj->query("short") || obj->query("prevent_drop"))  return 0;
return 1; }
 
 
// This procedure is called from the setup() function below.  It is
// basically here to check that existing users get whatever new settings
// they need to function in today's changing mudlib.

void consistency_check() {
    // if you think everyone has been "fixed" then what you put here should
    // moved to create() and taken out. 
    // right now it's empty because hopefully everyone has been updated.
    string euid, path, *bins;
    string str;
    int foo;
 

// Inspiral begins.
// NB this not to be moved to create.  it is here because
// the env is now   channels_verbose
	if( this_object()-> getenv( "channels_quiet_entry" ) )
		this_object()-> remove_env( "channels_quiet_entry" );
// Inspiral is done.
    // Add /cmds/wiz to wizard's command paths.  Pallando.  930722
    euid = geteuid( this_object() );
    seteuid( ROOT_UID ); // Yes, I know this is a security loop hole.
    if( wizardp( this_object() ) && ( path = query( "PATH" ) ) )
    {
        if( -1 == member_array( "/cmds/wiz", explode( path, ":" ) ) )
            set( "PATH", path + ":/cmds/wiz" );
    }
    // Remove /cmds/channels from the path if they have it. Buddha 930826
    if( wizardp( this_object() ) && ( path = query( "PATH" ) ) )
    {
         bins = explode(path, ":");
         if (member_array("/cmds/channels", bins) != -1)
         {
              bins -= ({ "/cmds/channels" });
              set( "PATH", implode(bins, ":") );
         }
    }

    // Change /cmds/refs to /cmds/object if they have it. Pallando 930824
    if( wizardp( this_object() ) && ( path = query( "PATH" ) ) )
    {
	bins = explode(path,":") ;
	foo = member_array("/cmds/refs",bins) ;
	if( foo != -1 ) bins[foo] = "/cmds/object" ;
	set( "PATH", implode(bins,":")) ;
    }
    seteuid( euid );

    if (!query("languages") || !mapp(query("languages"))) {
	switch (query("race")) {
	    case "human" : {
		set ("languages", ([ "common" : 100, "human" : 100 ]) ) ;
		break ;
	    }
	    case "elf" : {
		set ("languages", ([ "common" : 100, "elvish" : 100 ]) ) ;
		break ;
	    }
	    case "dwarf" : {
		set ("languages", ([ "common" : 100, "dwarvish" : 100 ]) ) ;
	    	break ;
	    }
	    case "gnome" : {
		set ("languages", ([ "common" : 100, "gnomish" : 100 ]) ) ;
		break ;
	    }
	    case "orc" : {
		set ("languages", ([ "common" : 100, "orcish": 100]) ) ;
		break ;
	    }
	    default : {
		set ("languages", ([ "common" : 100 ]) ) ;
	    }
	}
    }
}

//  This function is called when the player enters the game. It handles
//  news displays, player positioning, and other initial user setups.
 
void setup() {
   string *news;
   int i;
   
   //	Check to see if the user body has a "name"
 
   if(!query("name"))  return;
   seteuid(getuid()) ;
 
   //	Initiate user shell setup protocal

   this_object()->init_setup();
 
   //	Display last logon and logon site
 
   if(link_data("last_on"))
   write("\nLast logon:  " + ctime(link_data("last_on")) + " from " +
	 link_data("ip") + ".\n\n") ;
 
   debug("Setup: Running the consistency check.\n");
   
   consistency_check();  // A catch-all to upgrade old users
 
   debug("Setup: Setting special flags and reading news.\n");
   
   if(query("inactive"))   delete("inactive");
 
   CHANNELS_D -> initialize_user();

   if( !query("cwd") ) set("cwd", "/doc");
 
   //	Get the news from the news daemon and put it out line by line
   //	to avoid overloading one write output.
 
   news = explode( (string)MSG_D->display_news(), "\n");

   for(i=0; i<sizeof(news); i++)
	write( news[i] + "\n" );
 
#ifdef NO_LOGIN_PAUSE
   complete_setup();
   return;
#endif
 
   write("[Press ENTER to continue]  ");
   input_to("complete_setup",2);
 
return; }
 
//	Complete remainder of character setup after NEWS 
//	has been read by the entering player
 
static void complete_setup (string str) {
   object ghost;
   string temp, student_time;
 
/*
This is here to permit an admin to shut down the game from the
"Press ENTER to continue" prompt. Sometimes this is helpful if there
is an object that is interfering with commands or otherwise wedging
the game, but will go away if the game is reset. It's not a security
problem because only admins can use it, and they could just log in
and use the shutdown command anyway... ;)
*/

#ifdef SAFETY_SHUTDOWN
   if (member_group(getuid(this_object()),"admin")) {
      if (str=="shutdown") {
         CMD_SHUTDOWN->cmd_shutdown("0 because safety shutdown invoked.") ;
      }
   }
#endif

   write("\n");
 
   link->set("last_on", time());
      link->set("ip", query_ip_name(this_object())) ;

   set("reply", 0);  set("wreply", 0);

 
   debug("Complete_setup: Moving to the start location.\n");
 
   temp = getenv("START") ;
   if(!(temp && stringp(temp) && move(temp) == MOVE_OK)) {
      temp = query("start_location");
#ifdef REAPPEAR_AT_QUIT
      if(!(temp && stringp(temp) && move(temp) == MOVE_OK))
   	   move(START);
#else
	   move (START) ;
#endif
   }
 
   call_out("save_me", 1);
 
   ANNOUNCE->announce_user(this_object(), 0);
 
#if 0
This is commented out because of a problem with socket handling
by some versions of UNIX. Basically, if you make the call to USERID_D,
then the driver will call back to the user's host machine and ask for
the user's account name. Under some OS's (Ultrix and HP_UX to name two,
but there may be more) if the query returns "Host is unreachable", eg if
there is a firewall machine between the driver and the user's machine,
then the driver will break the user's connection, and anyone from that machine
will be unable to play the MUD.
You can undefine this at your own risk, but you'll be cutting off anyone
from a protected site, which means most .com addresses and a fair
smattering of other hosts, if your OS behaves this way. TMI-2's host
runs Ultrix, so we leave it commented out. A good 90% of hosts don't
support the user name query protocol anyway, so we're not losing that
much. It's your decision if you want to get the names of the other 10%
of users, or leave it commented out...
   USERID_D->query_userid();
#endif
   debug("Complete_setup: Checking to see if user is dead.\n");
 
   if(link_data("dead")) {
      ghost = create_ghost();
      this_object()->move( VOID );
      ghost->force_me("look");
      tell_object(ghost, "\nYou suddenly realize that you are still " +
		  "a ghost.\n");
      tell_room(environment(ghost), query("cap_name") + 
		" enters the game.\n", ({ ghost }));
      remove();
   return; }
 
   if(visible(this_object()))
   say(query("cap_name") + " enters the game.\n");
 
#ifdef LOGIN_LOG
   log_file(LOGIN_LOG, query("cap_name") + ": logged in from " +
	    query_ip_name(this_object()) + " [" +
	    extract(ctime(time()), 4, 15) + "]\n");
#endif
 
   command("look");
 
   student_time = STUDENT_D->query_time_left(query("name"));
 
   if(student_time != -1) {

	if(!student_time)
	write(blink("\n [WARNING:  Your time period as a student has " +
	      "ended]") + "\n\n");
   else write("\n [You have " + bold(format_time(student_time, 1)) + " left " +
	      "as a student]\n\n");
   }

   debug("Complete_setup: Setup complete.\n");
 
}

//  This function is called cyclically to save the user data
//  periodically, if AUTOSAVE is defined.
 
static void autosave_user() {

   remove_call_out("autosave_user");
   call_out("autosave_user", AUTOSAVE);
 
   if(!wizardp(this_object()))
      tell_object(this_object(), "Autosave.\n");
 
   save_me();

}
 
void heart_beat() {
   int age;
 
      continue_attack() ;
      unblock_attack() ;
      heal_up() ;
 
#ifdef IDLE_DUMP
   if(this_object() && interactive(this_object()) && !wizardp(this_object()) &&
      query_idle(this_object()) > IDLE_DUMP)
	this_object()->call_user_dump("idle");
#endif
 
   //	Add to the user's online age total.

   age = query("age");
 
   if(!query_temp("last_age_set"))  
	set_temp("last_age_set", time());
 
   age += (time() - query_temp("last_age_set"));
   set_temp("last_age_set", time());
   ob_data["age"] = age;

}

 
//  This function returns whether the user is linkdead or not.

nomask int query_linkdead() {  return !interactive(this_object());  }
 
void net_dead() {
 
   save_data();
   say((string)this_object()->query("cap_name") + " has gone net-dead.\n");
// check_team() ;
   PARTY_D->check_party(this_object()) ;
   ANNOUNCE->announce_user(this_object(), 3);
   CMWHO_D->remove_user(this_object());
   set_heart_beat(0);
 
#ifdef LINKDEAD_DUMP
   call_out("call_user_dump", LINKDEAD_DUMP, "linkdead");
#endif
 
#ifdef NETDEAD_LOG
   log_file(NETDEAD_LOG, link_data("cap_name") + ": net-dead from " +
	    query_ip_name(this_object()) + " [" +
	    extract(ctime(time()), 4, 15) + "]\n");
#endif
 
   link->remove();
}
 
void restart_heart() {
   say(query("cap_name")+" has reconnected.\n");
   write("Reconnected.\n");
   ANNOUNCE->announce_user(this_object(), 2);
   USERID_D->query_userid();
   set_heart_beat(1);
   set("inactive", 0);
   remove_call_out("call_user_dump");
 
#ifdef RECONNECT_LOG
   log_file(RECONNECT_LOG, query("cap_name") + ": reconnected from " +
	    query_ip_name(this_object()) + " [ " +
	    extract(ctime(time()), 4, 15) + "]\n");
#endif
 
}
 
void call_user_dump(string type) {

   tell_object(this_object(), " ");  		//  Beep em
   tell_object(this_object(), "\nSorry, you have idled too long.\n");
 
   if(environment()) {

   if(type == "linkdead")
   tell_room(environment(), "A janitor suddenly appears and sweeps " +
	     query("cap_name") + " into a nearby vortex.\n",
	     ({ this_object() }));
   else tell_room(environment(), query("cap_name") + " has idled too " +
		  "long.\n", ({ this_object() }));
   }
 
   this_object()->quit();

}
 
static void die() {
   object killer, ghost, corpse, coins, *stuff;
   mapping wealth ;
   string *names, name ;
   int i, res, totcoins ;

   //	Set the user's killer variable
 
   killer = query("last_attacker");
   if (!killer) killer = previous_object() ;
 
   //	If the wizard has themself set to "immortal", then
   //	they cannot die ... stop death call.
 
   if(wizardp(this_object()) && query("immortal")) {
   write("Your immortality protects you from certain death.\n");
   return; }

   //	If the user is already dead ... stop death call.
 
   if(link_data("dead"))  return ;
 
   // Bail out of any parties they may be involved in.

// check_team() ;
   PARTY_D->check_party(this_object()) ;
 
   //	Announce the user's death

   write("You have died.\n");
 
   say(query("cap_name") + " has died.\n", ({ this_player() }) );
 
   init_attack() ;
 
   //	Setup corpse with user's specifics
 
   corpse = clone_object("/obj/corpse");
 
   corpse->set_name(query("cap_name")) ;
 
   i = query("mass") ;
   if (i>0) corpse->set("mass", i) ;
 
   i = query("bulk") ;
   if (i>0) corpse ->set("bulk", i) ;
 
   i = query("capacity") ;
   if (i>0) corpse ->set ("capacity", i) ;
 
   i = query("volume") ;
   if (i>0) corpse ->set("volume", i) ;
 
   corpse->move(environment(this_object()));
 
   stuff = all_inventory(this_object());
 
   for(i=0;i<sizeof(stuff);i++)
     if(!stuff[i]->query("prevent_drop") && !stuff[i]->query_auto_load())
	stuff[i]->move(corpse);
 
   wealth = query("wealth") ;
   if (wealth) {
      names=keys(wealth) ;
      for (i=0;i<sizeof(wealth);i++) {
	 coins = clone_object(COINS) ;
	 coins->set_type(names[i]) ;
	 coins->set_number(wealth[names[i]]) ;
	 totcoins = totcoins + wealth[names[i]] ;
	 if (coins) coins->move(corpse) ;
      }
   }
   set ("wealth", ([])) ;
 
   res = query("capacity") ;
   set ("capacity", res + totcoins) ;
 
   if(killer)  name = (string)killer->query("cap_name");
 
#ifdef KILLS
   if(killer)
   log_file(KILLS, query("cap_name") + " was killed by " +
	    (name ? name + " " : "") + "(" + file_name(killer) +
            ") [" + extract(ctime(time()), 4, 15) + "]\n");
   else
   log_file(KILLS, query("cap_name") + " was killed by something [" +
	    extract(ctime(time()), 4, 15) + "]\n");
#endif
 
   //	Switch user to ghost body
 
   ghost = create_ghost();
 
   if(!ghost)  return;
 
   tell_object(ghost, "\nYou have a strange feeling.\nYou can see your own " +
	 	     "lifeless body from above.\n\n");
 
   if(killer) {
     ghost->set("killer_ob", killer);
     ghost->set("killer_name", (string)killer->query("name"));
   }
 
   //  Use a call_out to make sure all the above calls have 
   //  completed their required processing (so we don't lose
   //  this_object() before everything is done).
 
   call_out("remove", 0);
 
}

string query_short() {
 
   if(query("name") == "noname")  return "Noname";
 
   if(!interactive(this_object()))  
	return (query("title") + " [disconnected]");
 
   if(query("inactive"))  return query("cap_name") + " is presently inactive";
   else if(this_player() && attackers && sizeof(attackers) &&
	   environment(this_player()) == environment(this_object()))
	return query("cap_name") + " is attacking " +
		capitalize((string)attackers[0]->query("name")) + ".";
   else if (interactive(this_object())) return query("title");
}

string query_title() {
   string str, foo, fii;
 
   str = getenv( "TITLE" );
   if( !str ) str = query("cap_name");
   else if( !sscanf(str, "%s$N%s", foo,fii) )
      str = query("cap_name") + " " + str;
   else str = substr( str, "$N", query("cap_name") );
   return str;
}

nomask void catch_msg(object source, string *msg) {
   int i;
   for (i=0;i<sizeof(msg);i++) 
   receive(msg[i]);
}

void hide(int i) {
	set_hide(i);
}

/* EOF */
