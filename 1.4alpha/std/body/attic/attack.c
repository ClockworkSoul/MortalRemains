/*
// Program: /std/body/attack.c
// Written mostly by Buddha@TMI
// Originally based on the attack.c found in the mudlib.n,
// many structural similarites may remain.
// It is is a part of the TMI distribution mudlib.
// Please retain this header if you use this file.
// Much work was done in December of 1991.
// revised 2-16-92 by Buddha
// revised again 3-1-92 by Buddha
// Rewritten to remove the LOC, and to update it for mudlib 0.9, by
// Mobydick@TMI-2, 9-21-92
// Added some stuff to make monsters remember and attack old opponents.
// Mobydick, 2-3-93.
// Continue_attack is called from heart_beat..
// here is where we can try to see if we're dead or in combat.
// Added receive_damage() and receive_healing() systems, Watcher 3-27-93
// 01 Jul 97  Cyanide finally added "resistance" - meant to set
//      resistances in objects that already have it set...  it should
//      be set directly otherwise...  but it will work to set.  ;)
//		Also, on this day, I AD&D-ized calc_armor_class().
// 22 Jul 97  Cyanide added monitor().
// 10 Aug 97  Cyanide added query_save() - which invokes a function
//		of the same name in the property daemon.
// 28 Aug 97  Cyanide moved Ilzarion's big, ugly, "natt"-determining
//      chunklet to the less bulky property daemon.
// 08 May 97  Cyanide installed his Ultra Supreme version. 
//		Do you like me?
// 15 sep 97  Ilz puts in query_hit() - sees if u hit
// 26 Sep 97  Cyanide added the "weap" argument to see if a weapon
//		was used to hit, as opposed to a spell.
// ?? Oct 97  Ilzarion did a bunch of stuff it to heal_up()
// 06 Nov 97  Cyanide moved cast_spell from here to /std/spell.c
// 09 Nov 97  Cyanide added support for "foresight" spell (W9 - Div) to
//		kill_ob() and receive_damage().
// 23 Apr 98  Cyanide moved this code to attack.c and updated it.
// 13 May 98  Cyanide added add_experience(). See function.
// 13 Jun 98  Cyanide added a few hit messages.
// 02 Nov 98  Cyanide cleaned up alot. Fixed formatting probs.
*/


// Basic structure:
// The function kill_ob is used to initiate combat. The kill command calls
// it in any monster or player entering combat, as do the combat spells and
// other nastiness. It also turns on a monster's heartbeat if that is
// necessary.
// The heart_beat calls the continue_attack function. This function checks
// to see if the monster is dead and if so, starts the death sequence. It
// then checks the list of current opponents and removes any that are dead
// or otherwise out of the MUD. Opponents that have left the room are moved
// onto the "will_kill" list. It then checks to see if spellcasting or
// other activity has blocked the attack. If not, it calls execute_attack
// which does the actual attack against the first attacker on the list.

#include <body.h>
#include <config.h>
#include <stats.h>
#include <daemons.h>
#include <mudlib.h>
#include <commands.h>
#include <messages.h>
#include <numbers.h>

// Set this to see "Name attacks three times with her longsword."
#define SHOW_NUM_ATTS 1

// Set this to make invisible people appear as "Somebody"
// It won't work fully until we resolve the conflict between
// the "old_inv" technique and the visible efun. May have to
// write a small function to do the logic.
#define RESPECT_INVIS 1

inherit SECURE_OBJECT ;

// Prototypes for things that come in through the body object.

void run_away();
int query_vision();
int query_skill(string);
int kill_ob (object victim) ;
void set_verbs(string *verbs) ;
void set_verbs2 (string *verbs) ;
string *get_verb() ;
void cease_all_attacks();
void continue_attack() ;
int execute_attack(int, int, int);
int clean_up_attackers();
static void die();
mixed link_data(string what);
void output_attack (int damage, object weap, int num_att);
varargs mixed set(string prop, mixed arg, mixed security) ;

static object *attackers, target, *will_attack; // wombled by Buddha
static int any_attack ;
static string qs, *verbs, *vb, *vb2 ;
private static int heal_time ;


/*********************************************************/

// Function: receive_damage
// Purpose: Handles the damage calls from battle. It only accepts
// 		positive damage calls. receive_healing() should be used 
//		for healing.
// Credits:
//		27 Mar 93  Created by Watcher
//		27 May 97  Cyanide added support for damage types.
//      06 Jul 98  Cyanid moved the wimpy check to here.

varargs int receive_damage(int damage, string type, object camel, int weap) {
    // "Camel" after the Great Nightmask, for whom the camel was necessary.
    // Camel is, of course, the object attacking or doing the damage.

    int total, tmp, dam, i, *percy;  
    string *i_types, action;
    mapping resist_info;
    object *obs, ob;

    if (damage<0) return 0;
    ob = present("#FORESIGHT#", this_object());
    if (ob) {
	action = ob->query("action");
	this_object()->force_me(action);
	ob->remove();
	return 0;
    }

    if (!weap) weap=0; // If weap==1, a weapon/physical attack was used.
    set ("last_attacker", previous_object()) ;

    if ((type) && (member_array(type, VALID_DAMAGE_TYPES)!=-1)) {
	resist_info = (mapping)query("resist_type");
	if (resist_info) {
	    i_types = keys(resist_info);
	    percy = values(resist_info);

	    i = member_array(type, i_types);   
	    if (i != -1 && type != "wizard")
		damage = (percy[i]*damage)/100;
	} else {
	    // Nonstandard damage type - return 0
	    return 0;
	}

	if (!camel) camel = previous_object(); 
	if (!camel) camel = this_object()->query_current_attacker();

	total = damage;

	if (present("#REFLEXIVE_SPELL#", this_object())) {
	    obs = all_inventory(this_object()); 
	    for (i=0; i<(sizeof(obs)); i++) {
		if (obs[i]->query("id") &&
		  member_array("#REFLEXIVE_SPELL#", 
		    (string *)obs[i]->query("id")) != -1) {
		    tmp = (obs[i]->reflex(damage, type, camel, 
			weap));
		    if (!damage) dam=0;
		    else dam=(tmp*100)/damage;

		    total = (dam*total)/100;
		}
	    }
	}
    }

    if (damage <= 0 || link_data("dead") || 
      query("hit_points")<0 || query("linkdead"))  
	return 0;

    damage = total;
    dam = query("hit_points") - damage;
    if(dam < 0)  dam = -1;

    set("hit_points", dam);
    if (!weap) this_object()->monitor(damage, type);

    dam = (int)query("rest");     //Redefining a variable.  Sorry.
    if (dam>=2) {
	tell_object(TO, "A sudden jolt of pain jerks you from "+
	  "your slumber!\n");
	message(MSG_COMBAT, query("cap_name")+" wakes with a start!\n",
	  environment(TO), ({TO}) );
	set("rest", 1);
	this_object()->block_attack(dam);
    } else {
	if (dam==1) {
	    tell_object(TO, "You scramble to stand up!\n");
	    message(MSG_COMBAT, query("cap_name")+" scrambles to"+
	      " stand up!\n", environment(TO), ({TO}));
	    delete("rest");
	    this_object()->block_attack(2);
	}
    }

    return damage;

}  // end receive_damage()

/*********************************************************/

// Function: Receive_healing()
// Purpose: This function handles the healing calls from 
//		spells. It only accepts positive healing calls.  
//		Receive_damage() should be used for damage.
// Credits:
//		27 Mar 93	Created by Watcher

int receive_healing(int healing) {
    int heal, maxhp, woundlevel;

    if(healing <= 0 || link_data("dead") || query("hit_points") < 0)
	return 0;

    if(present("#HEARTSTONE_SPELL#", this_player())){
	write("Your heart of stone keeps you from recovery!\n");
	return 0;
    }

    maxhp = query("max_hp");

    heal = query("hit_points") + healing ;
    if(heal > maxhp) heal = maxhp;

    set("hit_points", heal);
    if (this_object()->monitor(-1 * healing, "healing"));

    return 1; 
}

/*********************************************************/ 

// Function: int resistance()
// Purpose: This function alters the objects resistance to the given
//		damage type by the given percentage.
// Receives:
//		string type		The damage type.
//		int percy		The percentage change
// Credits:
//		Created by Cyanide.

int resistance (string type, int percy) {
    mapping resists;
    string *type_old;
    int *percent_old, n;

    type = lower_case(type);
    if (type == "wizard") return 0;

    resists = (mapping)query("resist_type");
    if (resists) {
	type_old = keys(resists);
	percent_old = values(resists);

	n = member_array(type, type_old);
	if (n == -1) {
	    add("resist_type", ([ type : percy ]) );
	} else {
	    percy = (percent_old[n]*percy)/100;
	    set("resist_type/"+type, percy);
	}
    } else {
	set("resist_type", ([ type : percy ]) );
    }

    return 1;
}	// end resistance()

/*********************************************************/

// Function: calc_armor_class ( void )
// Purpose: This function updates the object's AC. It got 
//		moved out of the player object so monsters could have it 
//		too.
// Credits:
//		Created by ??
//		01 Jul 97	Cyanide AD&D-ized calc_armor_class().
//		?? ??? ??	Revamped by Ilzarion
//		10 May 98	Cyanide streamlined a bit.

int calc_armor_class() {
    mapping armor, magic_armor ;
    int ac, bac, bac2, mac, i;
    mixed types;

    armor = query("armor") ;
    if (!armor) armor = ([]);

    magic_armor = query("magic_armor");
    if (!magic_armor) magic_armor = ([]);

    // Ilzarion assumes a base ac (put it in the consistency 
    // check if we have problems)

    if (!undefinedp(query("base_ac"))) 
	bac = (int)query("base_ac") ;
    else
	bac = 10;
    bac2 = bac;

    types = values(magic_armor) ;
    for (i=0;i<(sizeof(types));i++)
	bac -= types[i];
    if (bac<-10) bac = -10;

    types = values(armor) ;
    for (i=0;i<(sizeof(types));i++)
	bac2 -= types[i];
    if (bac2<bac) bac = bac2;

    set("armor_class", bac);

    return bac ;
}

/*********************************************************/

// Function: unblock_attack ( void )
// Purpose: This function is used to prevent a player from 
//		attacking for a time. It is called by the wield command,
//		the various spells, other places. Anything a players does
//		that should interfere with his combat should call this.
// Credits:
//		?

void block_attack (int t) {
    int i;

#ifdef BLOCK_ATTACK
    i = query("stop_attack");
    set("stop_attack",i+t);
#endif
}

/*********************************************************/

// Function: void unblock_attack ( void )
// Purpose: This is called in the heart_beat() to decrease the 
//		blocking time.
// Chnages:
//  02 Nov 98  Cyanide took out invoke delay and cast delay.
//              They should be gone by now, anyways.

void unblock_attack() {
    int i ;

    i = query("stop_attack")-1 ;
    if (i>-1) set ("stop_attack",i) ;

    i = query("power_delay") - 1;		// Cyanide added 28 July 97
    if (i>-1) set ("power_delay", i);

    i = query("blind")-1 ;
    if (i>-1) set ("blind",i) ;

    i = query("stunned")-1 ;
    if (i>-1) set ("stunned",i) ;

    i = query("no_move")-1 ;			// Cyanide, 06 Jan 98
    if (i>-1) set ("no_move",i) ;
}

/*********************************************************/

// Function: int player_busy( void )
// Purpose: This function returns 1 if the player has stop_attack
//		set and 0 if not. It's probably a pretty stupid thing to 
//		use, since you should just query stop_attack directly, but
//		it's here if you want it.

int player_busy() {
    return query("stop_attack") ;
}

/*********************************************************/

// Function: void init_attack ( void );
// Purpose: This function is used to initialize various values.

void init_attack() {
    attackers = ({});
}

/*********************************************************/

// This function returns the current target if there is one. The 
// "current target" could be in another room, or dead, and not 
// cleaned out of the list yet, so be reasonably careful with this.

object query_current_attacker() {
    object ob;

    if(sizeof(attackers) == 0) 
	return 0;

    ob = attackers[0];
    if (!ob) return 0;

    if (environment(ob) != environment(TO))
	return 0;

    return ob;
}

/*********************************************************/

// This function returns the object at the top of the attackers list.

object query_attacker() {
    return query_current_attacker();
}

/*********************************************************/

// Function: int kill_ob ( object )
// Purpose: This is the 'kill' command. If the victim is not 
//		attacked yet, then it is entered first into the list
//		of victims. If it is already in the list, then it is
//		moved to the first entry.
// Receives:
//		object victim	Object to be attacked
// Returns:
//		2	Attack not allowed
//		?	Numbers are inconsistent.


int kill_ob (object victim) {
    object *prots, Ob;
    int i, lvl;
    string action;

    prots = query("protectors") ;
    if (prots && sizeof(prots)>0 && 
      (member_array(victim, prots) != -1) )
	return -1;

    // Cyanide thinks it's odd to attack yourself.  (5 Nov 97)
    if (victim == this_object()) return -1;

    if(query("linkdead"))  return 0;

#ifdef NO_PKILL
    if (userp(this_object()) && userp(victim)) {
	if (query("no_attack") || victim->query("no_attack"))
	    return 2;
    }

    // No_attack for users added by Blue, 941022.
#endif

    if (sizeof(attackers)) i = member_array(victim, attackers);
    else (i = -1);

    if (i != -1) {
	return 0;
    }

    Ob = present("#INVIS_OB#", this_object());
    if (Ob) Ob->upon_attacking();

    if (!attackers) {
	init_attack() ;
	attackers = ({ victim }) + attackers;
	any_attack = 1;
	set_heart_beat(1) ;
	victim->kill_ob(this_object());
	return 1;
    }

    attackers = ({ victim }) + attackers;
    any_attack = 1;

    prots = all_inventory(victim);
    Ob = present("#FORESIGHT#", victim);

    if (Ob) {
	action = Ob->query("action");
	victim->force_me(action);
	if (Ob)	Ob->remove();
	return 0;
    }

    victim->kill_ob(this_object());
    set_heart_beat(1) ;
    return 1;
}

/*********************************************************/

// This is a default heart_beat for living objects. There's a 
// player heart_beat in user.c and a monster heart_beat in 
// monster.c, both of which should override this one.

void heart_beat() {
    unblock_attack() ;
    continue_attack() ;
}

/*********************************************************/

// Call this to erase the list of opponents to attack. This will 
// NOT stop them from attacking you again...  ;)

void cease_all_attacks() {
    attackers = ({});
    any_attack = 0;
}

/*********************************************************/

// Call this function to remove a specific user from the attack array.

int remove_attacker(object obj) {
    if (member_array(obj, attackers) != -1)
	attackers -= ({ obj });
    return 1;
}

/*********************************************************/

// This function returns the whole attackers list. Same caveat as above.

object *query_attackers() {
    if (sizeof(attackers)==0)
	return 0 ;
    else
	return attackers ;
}

/*********************************************************/

// Function: set_attackers (object *att_list) 
// Purpose: Makes adding a bunch of attackers real easy.
// Credits: 
//		06 Jan 98	Cyanide created the function.

int set_attackers (object *att_list) {
    if (sizeof(attackers)) return 0;

    any_attack = 1;
    attackers = att_list;
    return 1;
}

/*********************************************************/

// Function: void run_away ( void )
// Purpose: This lets a wimpy player or monster run away. 
// Credits:
//		?? ??? ??	Created by Buddha@TMI
//		?? ??? ??	Buddha got this part working for the case of 
//					rooms with no exits. (Bad sign for the wimp.)
//		10 May 98	Cyanide added support for hidden exits.

void run_away() {
    int wimpy, i ;
    string direction, *hidden;
    mapping womble, tmp;

    womble = environment(this_object())->query("exits");
    hidden = environment(this_object())->query("hidden_exits");

    if (!womble) return;
    if (!hidden) hidden = ({});

    tmp = ([]);
    for (i=0;i<sizeof(keys(womble));i++) {
	if (member_array((keys(womble))[i], hidden)!=-1)
	    continue;
	tmp += ([ (keys(womble))[i]: (values(womble))[i] ]);
}

direction = this_object()->query("wimpydir") ;
if (!direction || !womble[direction]) {
    i = random(sizeof(womble));
    direction = keys(womble)[i] ;
}

tell_object(this_object(), "You flee to the "+direction+"!\n");
this_object()->move_player((values(womble)[i]), "", direction);

return ;
}

/*********************************************************/

// Function: void heal_up ( void );
// Purpose: This function restores spell points and hit points to 
//		the player and deals with his blood-alcohol level.
// Notes: Drunkenness is handled as follows: 0 indicates sobriety. 
//		Positive numbers indicate drunkenness, and diminish over 
//		time. When the player reaches drunkenness of 1, we then 
//		set his drunkenness to -6, where the negative number means
//		hangover rather than drunkenness, and we begin counting
//		up until we reach 0, at which time he's sober again.
// Credits:
//		?? ??? ??	Ilzarion did 1000 things to this function,
//					about 100 times. He did alot.
//		10 May 98	Cyanide cleaned up and pruned useless ghost
//					related stuff, and streamlined the sp/tp stuff
//					ALOT.

void heal_up() {
    int hp, sp, tp, maxh, maxs, maxt, heal = 0;
    int psp, maxp;
    int time, dr, rate, regen;
    object wound;

    heal_time++ ;
    time = query("time_to_heal") ;

    // If the healing rate wasn't set, then it's one hp/sp each 10 heartbeats.
    if (!time) time = 10 ;

    hp = query("hit_points") ;
    maxh = query("max_hp") ;

    // Check to see if it's time to improve hits and spells.
    if (heal_time > time) {
	sp = query("spell_points") ;
	psp = query("psionic_points") ;
	tp = query("theurgy_points") ;

	maxs = query("max_sp") ;
	maxp = query("max_psp") ;
	maxt = query("max_tp") ;

	heal_time = 0 ;
	dr = query("drunk") ;

	switch (dr) {
	case -1 : 
	    write ("Your headache clears up.\n") ;
	    break;
	case 1 : 
	    write ("Suddenly you have a massive headache.\n") ; 
	    break ;
	case 6 : 
	    write ("Your head is clearing.\n") ; 
	    break ;
	case 11 : 
	    write ("You feel drunk.\n") ; 
	    break ;
	case 16 : 
	    write ("The room stops spinning.\n") ; 
	    break ;
	case 21 : 
	    write ("You can see straight again.\n") ; 
	    break ;
	}

	// If the player's drunk is 1, we send him into 
	// hangover land.
	if (dr==1) {
	    dr=-6 ;
	    receive_damage(5, "wizard", TO, 0);
	}

	// Dry him out, or fix his hangover, as needed.
	if (dr>0) set ("drunk", dr-1) ;
	if (dr<0) set ("drunk", dr+1) ;

	if (hp==maxh && sp==maxs && tp==maxt) return ;

	// Notice: If the player is hung over, he heals LESS
	dr = dr/5+1 ;

	// Here we check for horrible bleeding wounds.
	wound = (present("#WOUND_OB#", this_player()));
	if (wound){
	    heal = (wound->query("woundlevel"));
	    heal *= -1;
	}

	if (hp<maxh) {
	    heal += (this_object()->query_level() + dr);
	    if ((int)query("stat/constitution") > 19)
		heal += ((int)query("stat/constitution") - 19);

	    regen = ((int)query("regeneration"));
	    if (regen)
		heal += regen;

	    heal += query("hit_points");

	    if(heal > maxh) heal = maxh;

	    set("hit_points", heal);
	    heal -= query("hit_points");
	    if (this_object()->monitor(-1 * heal, "healing"));
	}

	if (psp<maxp) {
	    int val = (int)query("stat/intelligence") + 
	    (int)query("stat/wisdom") +
	    (int)query("stat/constitution");
	    val /= 3;
	    psp += val/5;
	    psp += TO->query_level() / 3;
	    if (psp>maxp) psp = maxp;
	    set ("psionic_points", psp);
	} else {
	    set ("psionic_points", maxp);
	}

	if (sp<maxs) {
	    sp += ((int)query("stat/intelligence"))/5;
	    sp += TO->query_level() / 3;
	    if (sp>maxs) sp = maxs;
	    set ("spell_points", sp);
	} else {
	    set ("spell_points", maxs);
	}

	if (tp<maxt) {
	    tp +=((int)query("stat/wisdom"))/5;
	    tp += TO->query_level() / 3;
	    set("theurgy_points", tp);
	    if (tp<maxt) tp = maxt;
	} else {
	    set ("theurgy_points", maxt);
	}
    }	

    // This makes sure supernatural hit points don't get too high.
    if ((int)query("hit_points")>(maxh*2))
	set("hit_points", (maxh*2)) ;
}

/*********************************************************/

// Function:  int get_attacker_ac ( object )
// Purpose:  Figures out the AC of an object. It should 
//           soon be replaced by a reliable query()
// Recieves: object ob - ob to be calculated.
// Returns: int = armor class.
// Credits:
//    23 Apr 98   Cyanide pulled all this stuff out of 
//                execute_attack()

int get_attacker_ac (object targ) {
    int dex, ac;

    dex = PROPERTY_D->query_dex_ac_bonus(targ);
    ac = (int)targ->query("armor_class");
    ac -= (int)targ->query("magical_defense");
    ac -= dex;

    return ac;
}

/*********************************************************/

// This function determines which attackers are valid in a
// living object, and fixes the attackers array appropriately.

private int clean_up_attackers() {
    mixed *attackers_tmp;
    int i;

    attackers_tmp = ({ });

    for (i=0; i<sizeof(attackers); i++) {

	// If he's YOU - come to your senses.
	if (attackers[i] == this_object() )
	    continue;

	// If he's dead, then forget about him entirely.
	if (attackers[i] == 0 || !living(attackers[i]))
	    continue;

	// If he's not here, then forget about him.
	if (environment(attackers[i]) != environment(this_object()))
	    continue;

	// If he's a ghost, we've done enough to him already :)
	if ((int)attackers[i]->query_ghost() == 1) continue;

	// If we get this far, then we still want to be attacking him
	attackers_tmp += ({ attackers[i] });
    }

    // Copy the tmp list over to the attackers list.
    attackers = attackers_tmp;

    if (sizeof(attackers_tmp) == 0)
	any_attack = 0;

    return any_attack;
}

/*********************************************************/

// Changes:
//    06 Jul 98   Cyanide moved wimpy check to the end
//                so livings can get SOME combat in.

void continue_attack() {
    int hand, i, natt=0, old_inv;
    object weap1, weap2;	 // The weapon objects

    // The following are needed for output stuffs.
    int hand1, hand2;			// Natt of EACH HAND
    int damage1=0, damage2=0;	// Damage done by each hand.

    if (TO->query_skill("Ambidexterity")) 
	hand = 3;
    else
	hand = query("handedness");

    natt = PROPERTY_D->query_natt(TO);
    if ((!natt) || (natt<1)) natt = 1;

    if (query("hasted")) natt *= 2;

    weap1 = this_player()->query("weapon1");
    weap2 = this_player()->query("weapon2");

    //Check if this object has just died. if so, do the death stuff.
    if(query("hit_points") < 0) {
	die();
	return;
    }

    //If you're no allowed to attack (be it spell, or whatever)...
    if (query("prevent_attack")) return 0;

    // If there's no one to attack, then we are finished.
    if (!any_attack)  return;

    //Check to see if the player is doing something that prevents
    //him from making an attack.

    if (player_busy() > 0) {
	message(MSG_COMBAT, "You are too busy to make an attack!\n",
	  this_player());
	return;
    }

    //Call the clean_up_attackers function to see who's left. If it
    //returns 0, then there's no one left.
    if (!clean_up_attackers()) {
	// No attackers in room.
	message(MSG_COMBAT,
	  "Your pulse slows as you realize combat has ended.\n", TP);
	return;
    }

    // Before we print any messages, we need to make ourselves 
    // visible. Otherwise the person we're attacking doesn't get
    // the message. We become invisible again after the messages
    // are printed. This is klugey but real real easy.

    old_inv = query("invisible");
    set ("invisible", 0);

    // Ilzarion also wants to call the special attacks 
    // within the monster at this point.
    if (base_name(TO)!="/std/user") {
	if (TO->special_attack()) {
	    return;		
	}
    }

    hand1 = 0; hand2 = 0;
    if (weap1) hand1 = weap1->query("natt_bonus");
    if (weap2) hand2 = weap2->query("natt_bonus");

    if ( (weap1) && (weap2) ) {
	switch(hand) {
	case 1:
	    hand1 += natt; hand2 += 1;	// Right-handed:
	    for (i=0; i<hand1; i++)		// Attacks w/ right
		damage1 += execute_attack(0,0,1);
	    for (i=0; i<hand2; i++)		// Attacks w/ left
		damage2 += execute_attack(0,0,2);
	    break;
	case 2:
	    hand2 += natt; hand1 += 1;	// Left-handed:
	    for (i=0; i<hand2; i++)		// Attacks w/ left
		damage2 += execute_attack(0,0,2);
	    for (i=0; i<hand1; i++)		// Attacks w/ right
		damage1 += execute_attack(0,0,1);
	    break;
	default:			 
	    natt += (hand1 + hand2); 
	    hand1=0;  hand2=0;			//Ambidexterous...
	    for (i=0;(i<(natt+1));i++) {	//Use hands randomly.
		switch(random(2)+1) {
		case 1 :
		    hand1++;
		    damage1 += execute_attack(0,0,1);
		    break;
		case 2 :
		    hand2++;
		    damage2 += execute_attack(0,0,2);
		    break;
		}
	    }
	} // End switch(hand)

	//Cyanide notes how much better this new way is...
    } else {
	hand1 = 0;  hand2 = 0;
	if (weap1) {
	    hand1 += natt;
	} else {
	    if (weap2) {
		hand2 += natt;
	    } else {
		hand1 += natt;
	    }
	}

	// One of these, we know is 0, we just don't
	// know which one...
	natt = (hand1 + hand2);

	for (i=0;i<natt;i++) {
	    if (hand1) damage1 += execute_attack(0,0,1);
	    if (hand2) damage2 += execute_attack(0,0,2);
	}

    }

    // Do appropriate messages
    if (hand1) {
	if (!weap1) weap1 = TO;
	output_attack(damage1,weap1,hand1);
	if (sizeof(attackers) && attackers[0])
	    attackers[0]->monitor(damage1, 
	      weap1->query("damage_type"));
    }

    if (hand2) {
	if (!weap2) weap2 = TO;
	output_attack(damage2,weap2,hand2);
	if (sizeof(attackers) && attackers[0])
	    attackers[0]->monitor(damage2,
	      weap2->query("damage_type"));
    }

    // Restore the old invisibility setting.
    if (old_inv) set ("invisible", old_inv);

    //Check to see if we're under wimpy, and if so, run away.
    if ( this_object()->query("wimpy") > 0 ) {
	if ((query("hit_points")*100)/query("max_hp") < 
	  this_object()->query("wimpy")) {
	    call_out("run_away", 1);
	    return;
	}
    }

}  //end continue_attack()

/*********************************************************/

// Function: int execute_attack(int hit_mod, int dam_mod, 
//			int hand)
// Purpose:  Does all the mechanics of actual combat. It's
//			big, and it's ugly, and it's mostly Cyanide's.
// Recieves: object ob - ob to be calculated.
// Returns: int = armor class.
// Credits:
//	Original Authors: Sulam and Buddha @ The Mud Institute
//	09 May 97	Cyanide, after much pain, finaly succeeded
//				in overhauling execute_attack().
//	22 May 97	Cyanide completed the attack code. Added
//				support for attacking resting victims and
//				fighting in the dark.
//	27 May 97	Cyanide killed a couple bugs in combat and
//				added a busy check.
//	23 Apr 98	Cyanide streamlined ALOT, spawning get_attacker_ac()
//				Damage mods cannot exceed weapon's max damage 
//				now.


varargs int execute_attack (int hit_mod, int dam_mod, int hand) {
    int *damrange, str, ac, thac0, ran, hit_chance;
    int dmin, dmax, damage ;
    string name, damstr, damstr2, wepstr;
    string victim, vname, weapon_type;
    object *prots, weapon;

    // Check to see if primary target is dead, if so move to the next 
    // attack in the attackers queue. If the attackers queue is empty, 
    // stop attack call.
    if (!attackers || !sizeof(attackers))  return 0;
    if (attackers[0]->query("hit_points") < 0) {
	attackers -= ({ attackers[0] });
	if (!attackers || !sizeof(attackers))  return 0;
    }

    //Double check busy status, just in case.  Useful - trust me.
    if ((int)query("stop_attack") > 0) return 0;

    // Is the target being protected? If so, find the alternate target.
    prots = attackers[0]->query("protectors") ;
    if (prots && sizeof(prots)>0) {

	// Get rid of all ineligible protectors: dead or not present.
	prots = filter_array(prots,"valid_protect", this_object()) ;

	// If there are eligible protectors, then move the protector to the 
	// top of the list, adding him if needed.

	if (sizeof(prots)) {
	    attackers[0]->set("protectors", prots);
	    weapon = prots[random(sizeof(prots))] ;
	    ac = member_array(weapon,attackers) ;

	    if (ac>-1) {
		attackers[ac]=attackers[0] ;
		attackers[0]=weapon ;
	    } else {
		attackers = ({ weapon }) + attackers ;
		weapon -> kill_ob(this_object()) ;
	    }
	} else {
	    attackers[0]->set("protectors", ({}) );
	}
    }

    // hit_mod and dam_mod are modifiers that can be passed to
    // the attack. The heartbeat doesn't add them but you can 
    // make special attacks by calling execute_attack directly.
    // Be careful if you do so, you'll want to also call 
    // kill_ob to make sure a fight starts...

    if (!hit_mod) hit_mod=0 ;
    if (!dam_mod) dam_mod=0 ;

    // Attacking resting/sleeping creatures is sneaky and low,
    // but effective!!	-Cyanide 22 May 97

    if (query("rest")) return 0;

    str = attackers[0]->query("rest");
    if (str == 1) { hit_mod += 4; dam_mod += 2; }
    if (str == 2) { hit_mod += 20; dam_mod += 5; }

    // Collect the various statistics needed to get the 
    // hit chance and damage.

    thac0 = (int)query("thac0") - (int)query("magical_offence");
    str = PROPERTY_D->query_str_tohit(this_object());

    // Calculate the armor class...

    ac = get_attacker_ac(attackers[0]);

    if (!hand)  hand = (int)this_object()->query("handedness");
    if (!hand)  hand = 1;

    switch (hand) {
    case 2 : weapon = this_object()->query("weapon2"); break;
    default : weapon = this_object()->query("weapon1"); break;
    }

    // If they don't have a weapon, they get their intrinsic 
    // combat skills.
    if (!weapon) weapon = this_object();

    // Here we calculate the weapon stuffs.
    damrange = weapon->query("damage") ;
    if (!damrange) damrange = ({ 1, 6 });
    dmin = damrange[0] ;
    dmax = damrange[1] ;

    if (weapon != this_object()){ 
	wepstr = (string)weapon->query("name");
	weapon_type = (string)weapon->query("weapon_type");
	if (!weapon_type) {
	    weapon_type = ("Short Blades");
	} else { 
	    weapon_type = capitalize(weapon_type);
	}
    } else {
	wepstr = query("weapon_name") ;
	if (wepstr) wepstr = "fists";
	weapon_type = ("Unarmed");
    }

    name = query("cap_name") ;

    vname = attackers[0]->query("cap_name") ;

    // This is the combat formula.
    // If you are using drunkenness, and want it to affect combat, then
    // call query("drunk"), which goes 1-25, and subtract it from the
    // hit chance.
    // Cyanide thinks being drunk should fuck your shit up.

    hit_chance = ((21) - thac0 + (int)weapon->query("to_hit_adj") + 
      (int)weapon->query("temp_to_hit") + hit_mod + str + ac);
    //It's ugly. Sorry.	  -Cyanide

    // Here is where we check if you can see stuff.
    // Cyanide can't believe this has been neglected so long.  22 Mar 97

    if ((!query_vision()) && (!query("infravision")) ||
      (!CMD_LOOK->can_see(this_player(), attackers[0]) && 
	query_vision()) ) {
	if (query_skill("Blind Fighting"))
	    hit_chance -= 2;
	else
	    hit_chance -= 4;
    }  

    // Make hit_chance a range from 0 to 100 percent.
    hit_chance *= 5;

    // Constitution makes you less drunk, too...  (sorta)	
    // Cyanide's odd formula.
    if (query("drunk") > 0)
	hit_chance -=  ( (int)query("drunk") *
	  (26 - (int)query("stat/constitution")) ) / 7;

    // The hit chance is constrained to be between 5 and 95 percent.

    if (hit_chance<5) hit_chance = 5 ;
    if (hit_chance>95) hit_chance = 95 ;

    // This is the damage formula.
    // We have to calculate this first because we don't want to 
    // print messages of the form "You hit for zero damage." If 
    // the damage is less than zero, we print a "You miss" 
    // message regardless of the hit_chance roll.

    ran = random(100);
    str = this_object()->query_str_dam();
    dam_mod +=  str;

    // Dam_mod cannot exceed a weapon's maximum damage.
    // Cyanide, 23 Apr 98.
    if (dam_mod > dmax) dam_mod = dmax;

    dam_mod += (int)weapon->query("dam_adj") +
    (int)weapon->query("temp_dam_adj")+
    this_object()->query("dmg_bonus");

    damage = random(dmax-dmin) + dmin + 1;  //Dam_mod added later.

    // This supports for "enlargement" effects and whatnot.
    damage = (damage * (int)query("size"))/(int)query("SIZE");

    // If a monster has its "weap_resist" set, it is immune to
    // all weapons of less than that level of "enchantment" 
    // setting... 

    if (damage>0){
	if ((int)attackers[0]->query("weap_resist")>
	  (int)weapon->query("enchantment")) {
	    message(MSG_COMBAT, iwrap("Your weapon seems to be "+
		"useless against "+attackers[0]->query("cap_name")+
		"!"), TO);

	    message(MSG_COMBAT, iwrap(query("cap_name")+"'s weapon "+
		"does no damage at all "+"to "+attackers[0]->
		query("cap_name")+"!"), environment(), ({ TO, 
	      attackers[0] }));

	    message(MSG_COMBAT, iwrap(query("cap_name")+"'s "+
		"weapon simply bounces off you!"), attackers[0]);

	    return 0;
	}
    }

    // If positive damage, and the hit lands, then we do damage.

    if (damage>0 && ((random(100)+1) < hit_chance)) {
	str = attackers[0]->query("hit_points");
	damstr2 =  weapon->query("damage_type");
	if (!damstr2) damstr2 = "bludgeoning";

	// Critical hits and misses... (Cyanide 09 Apr 1997)
	// Here, we make hit_chance equal the minimum roll required
	// for a critical hit.

	hit_chance = query_skill(weapon_type);

	// Assume monsters at least know how to use their weapons.
	if (!userp(TO) && !hit_chance) hit_chance = 1;
	switch(hit_chance) {
	case 0 : hit_chance = 101; break;
	case 4..5 : hit_chance = 90; break;
	default : hit_chance = 95;
	}

	if (ran >= hit_chance) {
	    damage *= 2;
	    tell_object(this_object(), "You hit critically!\n");
	} 	  

	//Damge modifiers added after potential criticals.
	damage += dam_mod ;

	//Ilz is putting in a hit function now (sept 16th 97)
	if (damage>0) { 
	    damage = (weapon->hit_func(attackers[0], damage));
	    damage = attackers[0]->receive_damage(damage, 
	      damstr2, 0, 1); 
	}

	return damage;

    } else {
	return 0;
    }

} // End execute_attack()


/*********************************************************/


// Function: void output_attack(int damage, object weap, 
//			int num_att)
// Purpose:  Does all the combat output.
// Recieves: int damage:	The damage done
//			object weap:  The weapon used
//			int num_att:  Number attacks used.
// Returns: Void
// Notes:
//	This function was originally part of execute_attck(), but
//	the spam reducing project made it necessary to only do 
//	all this stuff once.
//
// Local Variables:
//	name		Attacker name
//	vame		Victim name
//	vobj		Objective of victim
//	verb1		The verb that the attacker sees
//	verb2		The verb that everyone else sees
//	wepstr		The weapon name
//	attacker	What the attacker sees
//	observers	What the observers see
//	victim		What the victim sees
//
// Credits:
//	Original Authors: Sulam and Buddha @ The Mud Institute
//	12 Oct 97  Cyanide TOTALLY redid damage messages and 
//			  added a total of 9 (count 'em: 9!) "miss" 
//			  messages.  Just 1 was BORING! 
//	23 Apr 98  Cyanide created this function and this header.
//  13 Jun 98  Cyanide added a bunch of Megaweapon's suggested
//            messages. We needed them anyway, with new combat.


void output_attack (int damage, object weap, int num_att) {
    string name, vname, vobj, verb1, verb2, wepstr;
    string poss, vposs, num, tmpstr;
    string attacker = "", observers = "", victim = "";
    mixed *contents;
    object attker = TO->query_current_attacker();
    int noise;

    if (!attker) return;

#ifdef RESPECT_INVIS
    name = "$N";
    vname = "$V";
#else
    name = query("cap_name");
    vname = attker->query("cap_name");
#endif

    vobj = objective((string)attker->query("gender"));
    poss = possessive(query("gender"));
    vposs = possessive(attker->query("gender"));

    if (!weap) weap = TP;
    if (!living(weap)) 
	wepstr = weap->query("name");
    else {
	wepstr = query("weapon_name");
	if (!wepstr || wepstr=="") wepstr = "fists";
    }

    if (!weap) wepstr = "fists";

    if (userp(TO)) {
	verb1 = "swing at";
	verb2 = "swings at";
    } else weap->get_verb();

    if (!verbs) {
	verb1 = "swing at" ;
	verb2 = "swings at" ;
    } else {
	verb1 = verbs[0];
	verb2 = verbs[1];
    }

    num = number(num_att);

#ifdef SHOW_NUM_ATTS
    if (num_att > 1) {
	attacker = iwrap("You attack "+num+" times with your "+
	  wepstr+".");
	observers = iwrap(name+" attacks "+num+" times with "+
	  poss + " " + wepstr+".");
	victim = observers;
    }
#endif

    if (damage>=-1) {

	switch (damage) {
	case -1..0:
	    attacker += iwrap("You "+verb1+" "+vname+" with your "+wepstr+
	      " and do nothing to "+vobj+".");
	    observers += iwrap(name+" "+verb2+" "+vname+" with "+poss+
	      " "+wepstr+" and does nothing to "+vobj+".");
	    victim += iwrap(name+" "+verb2+" you with "+poss+
	      " "+wepstr+" and does nothing to you.");
	    break;
	case 1:
	    attacker += iwrap("You "+verb1+" "+vname+" with your "+wepstr+
	      " and scratch "+vobj+".");
	    observers += iwrap(name+" "+verb2+" "+vname+" with "+poss+" "+
	      wepstr+" and scratches "+vobj+".");
	    victim += iwrap(name+" "+verb2+" you with "+poss+" "+wepstr+
	      " and scratches you.");
	    break;
	case 2..3 :
	    attacker += iwrap("You "+verb1+" "+vname+" with your "+wepstr+
	      " and barely nick "+vobj+".");
	    observers += iwrap(name+" "+verb2+" "+vname+" with "+poss+
	      " "+wepstr+" and barely nicks "+vobj+".");
	    victim += iwrap(name+" "+verb2+" you with "+poss+
	      " "+wepstr+" and barely nicks you.");
	    break;
	case 4..6 :
	    attacker += iwrap("You "+verb1+" "+vname+" with your "+wepstr+
	      " and hit "+vobj+".");
	    observers += iwrap(name+" "+verb2+" "+vname+" with "+poss+
	      " "+wepstr+" and hits "+vobj+".");
	    victim += iwrap(name+" "+verb2+" you with "+poss+
	      " "+wepstr+" and hits you.");
	    break;
	case 7..10 :
	    attacker += iwrap(vname+" grunts as you deal "+vobj+
	      " a solid blow.");
	    observers += iwrap(vname+" grunts as "+name+" deals "+vobj+
	      " a solid blow.");
	    victim += iwrap("You grunt as "+name+" deals you a solid blow.");
	    break;
	case 11..15 :
	    attacker += iwrap("You strike "+vname+" solidly, knocking "
	      +vobj+" back.");
	    observers += iwrap(name+" strikes "+vname+" solidly, knocking "
	      +vobj+" back.");
	    victim += iwrap(name+" strikes you solidly, knocking you back.");
	    break;
	case 16..21 :
	    attacker += iwrap("You knock "+vname+" around with your "+wepstr+".");
	    observers += iwrap(name+" knocks "+vname+" around with "+
	      poss+" "+wepstr+".");
	    victim += iwrap(name+" knocks you around with "+
	      poss+" "+wepstr+".");
	    break;
	case 22..28 :
	    attacker += iwrap("You "+verb1+" "+vname+" with your "+wepstr+
	      " and do "+vobj+" some serious damage.");
	    observers += iwrap(name+" "+verb2+" "+vname+" with "+poss+
	      " "+wepstr+" and does "+vobj+" some serious damage.");
	    victim += iwrap(name+" "+verb2+" you with "+poss+
	      " "+wepstr+" and does you some serious damage.");
	    break;
	case 29..36 :
	    attacker += iwrap("You beat the stew out of "+vname+
	      " with your "+wepstr+".");
	    observers += iwrap(name+" beats the stew out of "+vname+
	      " with "+poss+" "+wepstr+".");
	    victim += iwrap(name+" beats the stew out of you with "
	      +poss+" "+wepstr+".");
	    break;
	case 37..45 :
	    attacker += iwrap("You "+verb1+" "+vname+" with your "+wepstr+
	      " and tear into "+vobj+"!");
	    observers += iwrap(name+" "+verb2+" "+vname+" with "+poss+
	      " "+wepstr+" and tears into "+vobj+"!");
	    victim += iwrap(name+" "+verb2+" you with "+poss+
	      " "+wepstr+" and tears into you!");
	    break;
	case 46..55 :
	    attacker += iwrap(vname+" howls in pain from your "+
	      "vicious attack!");
	    observers += iwrap(vname+" howls in pain from "+name+
	      "'s vicious attack!");
	    victim += iwrap("You howl in pain from "+name+
	      "'s vicious attack!");
	    break;
	case 56..66 :
	    attacker += iwrap("You rip into "+vname+
	      " with deadly precision!");
	    observers += iwrap(name + " rips into "+vname+
	      " with deadly precision!");
	    victim += iwrap(name + " rips into you with "+
	      "deadly precision!");
	    break;
	case 67..78 :
	    attacker += iwrap("You "+verb1+" "+vname+" with your "+wepstr+
	      " and rip "+vobj+" gaping wounds!");
	    observers += iwrap(name+" "+verb2+" "+vname+" with "+poss+
	      " "+wepstr+" and rips "+vobj+" gaping wounds!");
	    victim += iwrap(name+" "+verb2+" you with "+poss+
	      " "+wepstr+" and rips you gaping wounds!");
	    break;
	case 79..91 :
	    attacker += iwrap("You mercilessly butcher "+vname+
	      ", shattering bone and splitting flesh!");
	    observers += iwrap(name+" mercilessly butchers "+vname+
	      ", shattering bone and splitting flesh!");
	    victim += iwrap(name+" mercilessly butchers you, shattering"+
	      " bone and splitting flesh!");
	    break;
	case 92..105 :
	    attacker += iwrap(vname+" will never be the same again as"+
	      " you devastate "+vobj+" with your "+wepstr+"!");
	    observers += iwrap(vname+" will never be the same as "+name+
	      " devastates "+vobj+" with "+poss+" "+wepstr+"!");
	    victim += iwrap("You will never be the same as "+name+
	      " devastates you with "+poss+" "+wepstr+"!");
	    break;
	case 106..120 :
	    attacker += iwrap("You can't help but smile as you utterly fuck "+
	      vposs+" shit up!");
	    observers += iwrap(name+" can't help but smile as "+
	      subjective(query("gender"))+" utterly fucks "+
	      vname+"'s shit up!");
	    victim += iwrap(name+" can't help but smile as "+
	      subjective(query("gender"))+" utterly fucks your shit up!");
	    break;
	case 121..136 :
	    attacker += iwrap("Blood flies through the air as you "+
	      "brutally maim "+vname+" with your "+wepstr+"!");
	    observers += iwrap("Blood flies through the air as "+name+
	      " brutally maims "+vname+" with "+poss+" "+wepstr+"!");
	    victim += iwrap("Blood flies through the air as "+name+
	      " brutally maims you with "+poss+" "+wepstr+"!");
	    break; 
	case 137..153 :
	    attacker += iwrap("You strike hard and fast at "+vname
	      +", spilling "+possessive(attker->query("gender"))
	      +"'s guts onto the ground!");
	    observers += iwrap(name+" strikes hard and fast at "+vname
	      +", spilling "+possessive(attker->query("gender"))
	      +"'s guts onto the ground!");
	    victim += iwrap("You gasp in astonishment as you watch "+name+
	      " spill your guts onto the ground!");	
	    break;  
	case 154..171 :
	    attacker += iwrap("The demons of Hell howl with pleasure at "+
	      "the mightyness of your blow!!");
	    observers += iwrap("The demons of Hell howl with pleasure at "+
	      "the mightyness of "+name+"'s blow!!");
	    victim += iwrap("The demons of Hell howl with pleasure at "+
	      "the mightyness of "+name+"'s blow!!");
	    break; 
	default:
	    attacker += iwrap("You KNOCK THE SHIT out of "+vname+
	      ", utterly evicerating "+vobj+" with your "+wepstr+"!");
	    observers += iwrap(name+" KNOCKS THE SHIT out of "+vname+
	      ", utterly evicerating "+vobj+" with "+poss+" "+
	      wepstr+"!");
	    victim += iwrap(name+" KNOCKS THE SHIT out of you, "+
	      "utterly evicerating you with "+poss+" "+wepstr+"!");
	    break;
	}

	// The routines below check to see if all the listeners really
	// want to hear how the battle is going (Watcher, 4/27/93).
	// Cyanide updated them for the new format (10 October 97)

	// Get a list of all in the room who are listening to the 
	// battle.

	contents = all_inventory(environment(this_object()));
	contents = filter_array(contents, "filter_listening", 
	  this_object());

	// Let's make this object hear it.
	if (!(query("noise_level") && damage < 2)) {

#ifdef RESPECT_INVIS
	    if (visible(attker, TO))
		tmpstr = replace_string(attacker, "$V", 
		  attker->query("cap_name"));
	    else
		tmpstr = replace_string(attacker, "$V", "Somebody");
#endif

	    message(MSG_COMBAT, tmpstr, this_object() );
	}

	// Now we make any observers hear/see it.
	for (int k=0; k<sizeof(contents); k++) {

	    if (contents[k])
		noise = (int)contents[k]->query("noise_level");

	    if (noise && (noise > 1 || (noise == 1 && damage < 2)))
		continue;

#ifdef RESPECT_INVIS
	    if (!visible(attker, contents[k]))
		tmpstr = replace_string(observers, "$V", "Somebody");
	    else
		tmpstr = replace_string(observers, "$V", 
		  attker->query("cap_name"));

	    if (!visible(TO, contents[k]))
		tmpstr = replace_string(tmpstr, "$N", "Somebody");
	    else
		tmpstr = replace_string(tmpstr, "$N", 
		  query("cap_name"));
#endif

	    message(MSG_COMBAT, tmpstr, contents[k]);
	}

	// Now the attacker hears it.
	if (attker && 
	  !(attker->query("noise_level") && damage < 2)) {

#ifdef RESPECT_INVIS
	    if (visible(TO, attker))
		tmpstr = replace_string(victim, "$N", 
		  query("cap_name"));
	    else
		tmpstr = replace_string(victim, "$N", "Somebody");
#endif

	    message(MSG_COMBAT, tmpstr, attker);
	}

    } else {	// if (damage>0)

	// If we got here, it means we missed the hit roll, or did zero
	// damage.

	vobj = subjective((string)attker->query("gender"));
	attacker = "You "+verb1+" "+vname+" with your "+wepstr;
	observers = name+" "+verb2+" "+vname+" with "+poss+" "+
	wepstr;
	victim = name+" "+verb2+" you with "+poss+" "+wepstr;

	switch (random(9)) {
	case 0 : 
	    attacker += " but you miss.";
	    observers += " but misses.";
	    victim += " but misses.";
	    break;
	case 1 : 
	    attacker += " but "+vobj+" dodges your clumsy attack.";
	    observers += " but "+vobj+" dodges "+poss+
	    " clumsy attack.";
	    victim += " but you dodge "+poss+
	    " clumsy attack.";
	    break;
	case 2 :
	    attacker += " but "+vobj+" easily avoids the blow.";
	    observers += " but "+vobj+" easily avoids the blow.";
	    victim += " but you easily avoid the blow.";
	    break;
	case 3 :
	    attacker += " but do no damage.";
	    observers += " but does no damage.";
	    victim += " but does no damage";
	    break;
	case 4 :
	    attacker += " but "+vname+" blocks your attack"+
	    " and prepares to counter.";
	    observers += " but "+vname+" blocks "+poss+
	    " attack and prepares to counter.";
	    victim += " but you block "+poss+
	    " attack and prepare to counter.";
	    break;
	case 5 :
	    attacker += " and deal a mighty blow to empty air.";
	    observers += " and deals a mighty blow to empty air.";
	    victim += " and deals a mighty blow to empty air.";
	    break;
	case 6 :
	    attacker = "You miss "+vname+" by an inch!";
	    observers = name+" misses "+vname+" by an inch!";
	    victim = name+" misses you by an inch!";
	    break;
	case 7 :
	    attacker = "You miss "+vname+" by a mile!";
	    observers = name+" misses "+vname+" by a mile!";
	    victim = name+" misses you by a mile!";
	    break;
	default :
	    attacker = "You miss.";
	    observers = name+" misses.";
	    victim = name+" misses.";
	    break;
	}

	// This object sees...	
	if (!query("noise_level")) {

#ifdef RESPECT_INVIS
	    if (visible(attker, TO))
		tmpstr = replace_string(attacker, "$V", 
		  attker->query("cap_name"));
	    else
		tmpstr = replace_string(attacker, "$V", "Somebody");
#endif

	    message(MSG_COMBAT, iwrap(tmpstr), this_object() );
	} 

	// Observers...
	for(k=0; k<sizeof(contents); k++) {

#ifdef RESPECT_INVIS
	    if (!visible(attker, contents[k]))
		tmpstr = replace_string(observers, "$V", 
		  "Somebody");
	    else
		tmpstr = replace_string(observers, "$V", 
		  attker->query("cap_name"));

	    if (!visible(TO, contents[k]))
		tmpstr = replace_string(tmpstr, "$N", "Somebody");
	    else
		tmpstr = replace_string(tmpstr, "$N", 
		  query("cap_name"));
#endif

	    message(MSG_COMBAT, iwrap(tmpstr), contents[k]);
	}

	// Victim, at last.
	if (attker && !attker->query("noise_level")) {

#ifdef RESPECT_INVIS
	    if (visible(TO, attker))
		tmpstr = replace_string(victim, "$N", 
		  query("cap_name"));
	    else
		tmpstr = replace_string(victim, "$N", "Somebody");
#endif

	    message(MSG_COMBAT, iwrap(tmpstr), attker);
	}
    }

    return;
} //end output_attack()	- finally!


/*********************************************************/


// The set_verbs function stores the list of verbs to be used when a player
// or monster makes an attack, and conjugates the verbs by adding an "s" to
// the end of each. You can use set_verbs2, below, to override this
// conjugation if you need to.

void set_verbs(string *verbs) {
    int i ;
    string w1, w2 ;

    vb = verbs ;
    vb2 = allocate(sizeof(vb)) ;
    for (i=0;i<sizeof(verbs);i++) {
	if (sscanf(verbs[i],"%s %s",w1,w2)==2) {
	    vb2[i]=w1+"s "+w2 ;
	} else {
	    vb2[i]=verbs[i]+"s" ;
	}
    }
}

/*********************************************************/

// This function is used to set the conjugated forms of the verbs. Use
// this when one of the attack verbs is irregular: there are some monster
// examples that do it.

void set_verbs2 (string *verbs) {
    vb2 = verbs ;
}

/*********************************************************/

// The get_verb function returns a random verb from the list of verbs.
// It returns bboth forms of the verb in a 2-element array.

string *get_verb() {
    int i ;

    i = random(sizeof(vb)) ;
    return ({ vb[i], vb2[i] }) ;
}

/*********************************************************/
// This func (as well as invoke_spell) is no longer in 
// use. It should be removed once we're sure that nobody 
// uses it anymore.

int cast_spell (int cost) {
    int sp;

    sp = (int)query("spell_points");

    if (cost>sp) return 0;

    set("spell_points", (sp-cost) );

    switch (cost) {
    case 0..15 : sp = 1; break;	//Reusing sp - sorry.
    case 16..35 : sp = 2; break;
    case 36..70 : sp = 3; break;
    default : sp = 4; break;
    }

    TP->add("power_delay", sp);
    TP->block_attack(1);
    return 1;
}

/*********************************************************/

int invoke_spell (int cost) {
    int sp;

    sp = (int)query("theurgy_points");

    if (cost>sp) return 0;

    set("theurgy_points", (sp-cost) );

    switch (cost) {
    case 0..15 : sp = 1; break;	//Reusing sp - sorry.
    case 16..35 : sp = 2; break;
    case 36..70 : sp = 3; break;
    default : sp = 4; break;
    }

    TP->add("power_delay", sp);
    TP->block_attack(1);
    return 1;
}

/*********************************************************/

// Monitor added by Cyanide 22 July 1997. Checks to see if
// the player has hp monitoring on, and if so, shows 
// current hp and sp.
// On 23 July 97, Cyanide added wizards getting damage and 
//      type notes.

void monitor(int damage, string type) {
    if ((damage<1) && (type!="healing")) return;

    if (query("monitor") && !query("dying")) {
	command("hp");

	if (wizardp(TO))
	    tell_object(TO, "(Monitor) Type: "+type+"	Damage: "+
	      damage+"\n");
    }
}

/*********************************************************/

// Cyanide wrote this because Ilz's didn't work, and he could'nt  
// be bothered to puzzle out the sloppy code. It always returned
// a 1!  (boggle).

int save_throw( int mod ) {
    int roll, saves;

    if (!mod) mod = 0;

    mod += (this_object()->query("save_bonus"));
    if (this_object()->query_skill("Iron Will")) mod++;
    if (this_object()->query_skill("Mental Resistance")) mod++;

    saves = (int)PROPERTY_D->query_save(this_object());
    if (!saves) saves = 18;

    roll = random(20)+1;

    switch(roll) {
    case 1  : saves = 0; break;
    case 20 : saves = 1; break;
    default : 
	if (roll < (saves - mod))
	    saves = 0;
	else 
	    saves = 1;
	break;
    }

    return saves;
}

/*********************************************************/

// Ilz cut and paste stuff from execute attack. It's ugly.

int query_hit(object obj, int bonus){

    int  hit_mod, dam_mod, str, dex, ac, thac0, old_inv, ran, hand, hit_chance;
    string name, verb1, verb2, vname,  wepstr, *verbs;
    string victim;
    mixed *contents;
    object *prots, weapon;

    // Collect the various statistics needed to get the hit chance and damage.

    thac0 = (int)query("thac0") - (int)query("magical_offence");
    str = PROPERTY_D->query_str_tohit(this_object());
    dex = PROPERTY_D->query_dex_ac_bonus(obj);

    ac = ((obj->query("armor_class")) -
      (obj->query("magical_defense")));

    if (!hand)  hand = (int)this_object()->query("handedness");
    if (!hand) hand = 1;


    switch (hand) {
    case 2 : weapon = this_object()->query("weapon2"); break;
    default : weapon = this_object()->query("weapon1"); break;
    }

    old_inv = 0;
    ran = 0;
    if (weapon) {
	old_inv =	(int)weapon->query("to_hit_adj");
	ran = (int)weapon->query("temp_to_hit");
    }
    // If they don't have a weapon, they get their intrinsic combat skills.

    hit_chance = ((21) - thac0 + old_inv + bonus +
      ran + hit_mod + str - dex + ac);
    //It's ugly. Sorry.	  -Cyanide


    // Make hit_chance a range from 0 to 100 percent.
    hit_chance *= 5;

    if (query("drunk") > 0)
	hit_chance -=  ( (int)query("drunk") *
	  (26 - (int)query("stat/constitution")) ) / 7;
    //Constitution makes you less drunk, too...  (sorta)	Cyanide's odd formula.

    // Attacking invisible creatures is really rather difficult.
    if ((int)obj->query("invisible")>0) hit_chance=hit_chance - 25 ;

    // The hit chance is constrained to be between 5 and 95 percent.


    //write ("hit chance is "+hit_chance+".\n");

    if (hit_chance<5) hit_chance = 5 ;
    if (hit_chance>95) hit_chance = 95 ;

    if (random(100) < hit_chance){
	return 1;
    }else{
	return 0;
    }
}

/*********************************************************/


// Function: int add_experience( int xpv );
// Purpose: 
//	1 - To add experience securely. The shit with Kyako
//		showed that paranoia is a GOOD thing.
//	2 - To show who the bad guys are, and to give us an
//		excuse to nuke anybody who adds experience to 
// 		players...   ;)
// Receives: int xpv  :  Experience to be added.
// Returns: integer equal to the xp actually added.
// Credits:
//	13 May 98  Cyanide created in fear of Kyakoisms.


int add_experience ( int xpv ) {
    if (!userp(TO) || xpv<1) return 0;

    return GUILD_D->add_experience(TO, xpv);
}

// Figure out the num or attacks.
int query_natt() {
    return PROPERTY_D->query_natt(TO);
}

int hit_func(object ob, int dam) {
    return dam;
}

int special_attack() { return 0; }

/* EOF */
