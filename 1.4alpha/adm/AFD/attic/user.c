#define DEBUG(X)          tell_object(find_player("chronos"), X)
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
// Chronos added death sequence, and logging of kills/deaths (07/02/95)
// (03-05-96) Chronos fixed bug with players dying and not losing money.
//            Modified wizard's immortality stuff, modified death code,
//            prototyped query_level(), minor fixes etc.
// (04-28-96) Chronos added a query_cap_name() and a query_possessive()
//            for the sake of compatibility.  query_ac() is now used
//            for determining armor class, not calc_armor_class().
//            Capacity and volume are now query_ functions, but as of
//            this moment they simply return the standard values.
//            Another stat has been added, "agility", which affects
//            armor class at higher levels, and "luck" has been added,
//            but it is completely invisible to players.  ;)
// (05-28-96) Chronos added handedness, modified combat a bit.
//            Made second attacks possible, using handedness. 
// (07-27-96) Chronos revamped a bit of the code, attempted to make it a bit
//            more efficient and pretty, and reworked the multiple attack
//            code.  Reworked armour and weapon classes in the user object.
// (09-12-96) Chronos added keeping objects ability.  When you die, you
//            unkeep all and when you quit, you unkeep all.  Silently
//            and automagically.  Also, you endfollow in either case too.
#include <config.h>
#include <login.h>
#include <commands.h>
#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <flock.h>
#include <move.h>
#include <channels.h>
#include <levels.h>
#include <money.h>
#include <priv.h>
#include <uid.h>
#include <switches.h>
// Some files are inherited by including user.h.
#include <user.h>
#include <user2.h>
#include <logs.h>
#include <body.h>
 
inherit LIVING ;

static void complete_setup (string str) ;
static void die();
static int create_ghost();
string query_title();
int query_permission(string prop);
int query_level() ;
void init_setup();
void destroy_autoload_obj();
varargs void execute_attack(int hit_mod, int dam_mod, int hand) ;
 
//  Setup basic and command catch systems
 
string query_cap_name() { return query("cap_name"); }
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
#ifndef INTERMUD
if(verb == "gwiz" || verb == "interwiz"){
		printf("Sorry, %s does not support intermud.\n",capitalize(mud_name()));
return 1;
}
#endif /* INTERMUD */
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
    int hand, i;
   mixed *contents;
 
	// Check if this object has just died. if so, do the death stuff.
   	if (query("hit_points") < 0) {  die();  return ;  }
 
	// If there's no one to attack, then we are finished.
   	if (!any_attack) return;
 
	// Call the clean_up_attackers function to see who's left. If it
	// returns 0, then there's no one left.
   	if (clean_up_attackers() == 0) {
/*  Chronos changed this because it lacks FLAVOR.  :)
        write("The combat is over.\n"); // No attackers in the room.
 */
  call_out("relax", 2);
      	return;
   	}
 
	// Check to see if the player is doing something that prevents
	// him from making an attack.
   	if (query("stop_attack")>0) {
//	write ("You are too busy to make an attack!\n") ;
   	return ;
   	}
 
	// Check to see if we're under wimpy, and if so, run away.
	if(query("hit_points")*100/query("max_hp") <
	   this_player()->query("wimpy")) {
       	  run_away();
       	  return;
   	}
        // Auto spell casting?
        if (query("autocast")) command((string)query("autocast"));
// If they are wielding two weapons, they get two attacks. ;)
// This is where they get their first, normal attack.
    if (query("right_hand") && query("left_hand")) {
        switch(query("hand")) {
          // If we are lefty, attack left, then try for right.
          case 0: hand = 2 ; execute_attack(0,0,1); break;
          // righty, attack right, try left.
          case 1: hand = 1; execute_attack(0,0,2); break;
          // ambi-freaks.  flip a coin.
          default : hand = random(2) + 1; execute_attack(0,0,random(2)+1);break;
        }
  // Hand tells us which hand they used.  1 = left, 2 = right.

// Get a list of all in the room who are listening to the battle.

        contents = all_inventory(environment(this_object()));
        contents = filter_array(contents, "filter_listening", this_object());
   if ((int)query_level()*3<random(100)) {
     for(i=0;i<sizeof(contents);i++) {
  if (!contents[i]) continue;
  if (contents[i]->query("noise_level")) continue;
     tell_object(contents[i], "Attacking again .. ");
     }
 		execute_attack(0,0,hand);
  }
     }
  else {  // if we are here, we have 1 weapon, or none.
  if ((int)query("hand")==1) execute_attack(0,0,1);
  else execute_attack(0,0,2);
  }
}

void relax() {
   tell_object(this_object(), 
      "Your pulse slows as you realize the melee has ended.\n");
      }

// This is the big, ugly CPU hogging function where the combat actually
// takes place.

static int loop, noise;
 
varargs void execute_attack (int hit_mod, int dam_mod, int hand) {

	int att_sk, def_sk, str, dex, ac, wc, hit_chance ;
	string name, verb1, verb2, vname, damstr, damstr2, wepstr, *verbs, qp;
	mixed *contents;
	object *prots ;
	object weapon ;
       int old_inv;
	string victim ;
	int *damrange ;

  if (!attackers) return ;
   if (attackers[0])
  attackers[0]->kill_ob(this_object());
  hit_chance = 0;
// Reusing a variable to save memory..
   if (query("right_hand")) hit_chance ++;
   if (query("left_hand")) hit_chance++;

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
       victim = prots[random(sizeof(prots))]->query("name");
// re-using a variable to save memory - sorry bout that :(
                  weapon = find_living(victim);
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

// Reusing weapon again to save memory.  Guilds are going to have different
// fighting advantages.  Muahaha.
   weapon = present("#GUILD_OBJECT#", this_object());
   if (weapon) {
     hit_mod += (int)weapon->query("hit_mod");
     dam_mod += (int)weapon->query("dam_mod");
   } 
 
// Collect the various statistics needed to get the hit chance and damage.
 
        str = this_object()->query("stat/strength") ;
	dex = attackers[0] ->query("stat/dexterity") ;
        ac = attackers[0]->query_ac();
        if (hand == 2) // 2 = right handed.
        weapon = this_object()->query("right_hand");
 	else	
        weapon = this_object()->query("left_hand");
 
   if (hand==1 && !weapon) weapon=this_object()->query("right_hand");
   if (hand==2 && !weapon) weapon=this_object()->query("left_hand");
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
                        weapontype = "Brawling";
	} else {
// If we get here, then the player has a weapon, and we query the weapon
// for its attack properties.
                wc = this_object()->query_wc();
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
// hit_chance == Number of weapons being use.
// (used)

  if (weapon) {
// If we are using one weapon...
// In the wrong hand.. 
   if (hit_chance == 1) {
  switch(query("hand")) {
  case 0:   // Lefties.
      if (hand==2) hit_mod += -45 + query("stat/dexterity");
      break;
  case 1:   // Righties.
   if (hand==1) hit_mod += -45 + query("stat/dexterity");
     break;
  default:  // Ambies.
     break;
  }
}  // end of 1 weapon mods.
  if (hit_chance == 2) {  // hit_chance reused to store # of weapons
  switch(query("hand")) {
  case 0: // for lefties
     if (hand==1) hit_mod += -35 + query("stat/dexterity");
     else hit_mod += -60 + query("stat/dexterity");
     break;
  case 1: // for righties.
     if (hand==2) hit_mod += -35 + query("stat/dexterity");
     else hit_mod += -60 + query("stat/dexterity");
     break;
  case 2: // for ambies
     hit_mod += -48 + query("stat/dexterity"); break ;
  }
 } // end of 2 weapon mods
 
}  // end of (if weapon)
// This is the combat formula.
// If you are using drunkenness, and want it to affect combat, then
// call query("drunk"), which goes 1-25, and subtract it from the
// hit chance.
// Chronos sez: BLOW ME.  Being drunk can mess you up when you're fighting.

   hit_chance = 30 + str + att_sk + 3*wc - dex - def_sk - ac/6 + hit_mod ;
        if (query("drunk")>0) hit_chance -= query("drunk")*3;
      if (!query("vision") || query("blind")) {
        if (query("blind") || !query("infravision")) {
          skill_improve_prob = 80 - query_skill("Blindfighting");
          hit_chance -= skill_improve_prob;
           skill_improve_prob = hit_chance - (100-hit_chance)/25;
  if (skill_improve_prob<0) skill_improve_prob=1;
  skill_improve_prob += query("luck")*2;
  if (random(100)<skill_improve_prob) 
               this_object()->improve_skill("Blindfighting", 1);
     }
}
 
  if (weapon)
  if ((int)attackers[0]->query("magic")>(int)weapon->query("magic")) {
  tell_object(this_object(),
     "Your weapon does no damage to "+attackers[0]->query("cap_name")+
   " at all!\n");
  message("combat", query("cap_name")+
     "'s weapon does no damage to "+attackers[0]->query("cap_name")+
 " at all!\n", environment(), ({ this_object(), attackers[0] }) );
   tell_object(attackers[0],
   query("cap_name")+"'s weapon simply bounces off you!\n");
  return ;
  }

 if ((string)attackers[0]->query("race")=="pixie")
  if (!random(95)) 
       {  tell_object(this_object(),
           attackers[0]->query("cap_name") +
                 " flutters gracefully away from your attack!\n");
       message("combat", attackers[0]->query("cap_name")+
        " flutters gracefully away from "+query("cap_name")+"'s attack!\n",
       environment(), ({ this_object(), attackers[0] }) );
     tell_object(attackers[0], "You flutter gracefully away from "+
          query("cap_name")+"'s attack!\n");
     return ;
      }                            
  if ((string)attackers[0]->query("race")=="halfling")
  if (!random(98))
       {  tell_object(this_object(),
           attackers[0]->query("cap_name") +
                 " swiftly rolls out from under your attack!\n");
       message("combat", attackers[0]->query("cap_name")+
        " swiftly rolls out from under "+query("cap_name")+"'s attack!\n",
       environment(), ({ this_object(), attackers[0] }) );
     tell_object(attackers[0], "You swiftly roll out from under "+
          query("cap_name")+"'s attack!\n");
     return ;
      }                            
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
  if ((string)query("race")=="pixie") damage -= random(10) + 2;
// This is the weapon_hit() function being called.
        if (weapon) 
          damage += weapon->weapon_hit(damage);

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
   if (damage) {
    if (weapon) attackers[0]->receive_damage(damage, weapon->query("damage_type"));
   else attackers[0]->receive_damage(damage);
  }
		qs = objective((string)attackers[0]->query("gender")) ;
    qp=possessive((string)attackers[0]->query("gender"));

  /*  These are the variables we have:
   *  name              Attacker name.
   *  vname             Victim name.
   *  qs                Objective of victim;
   *  qp                Possessive of victim;
   *  verb1             The verb that the attacker sees.
   *  verb2             The verb that everyone else sees.
   *  wepstr            The weapon name.
   *
   * damstr is what the ATTACKER sees.
   * damstr2 is what the OBSERVERS see.
   * victim     is what the VICTIM sees.  (reused variable to save mem)
   */
    switch (damage) {
      case 1: {
      damstr ="You "+verb1+" "+vname+" with your "+
                     wepstr+" and scratch "+qs+".";
       damstr2 = name +" "+verb2+" "+vname+ " with " + 
             possessive(this_object()->query("gender"))+" "+ 
                   wepstr + " and scratches "+qs+".";
       victim = name+" "+verb2+" you with " + 
              possessive(this_object()->query("gender"))+" "+ 
              wepstr + " and scratches you."; 
        break ;
      }  
      case 2..3 : {
        damstr = "You barely tap "+vname+" with your " + wepstr+ "." ;
        damstr2 = name+" barely taps "+vname+" with " +
            possessive(this_object()->query("gender"))+" " +wepstr+"." ;
        victim = name+" barely taps you with "+ 
          possessive(this_object()->query("gender"))+" " +wepstr+".";
        break ;
      }  
      case 4..6 : {
        damstr = "You hit "+vname+"." ;
        damstr2 = name+ " hits "+vname+"." ;
        victim = name+" hits you."; 
        break ;
      }
      case 7..9 : {
        damstr = vname+" grunts as you deal "+qs+" a solid blow.";
        damstr2 = vname+" grunts as "+name+" deals "+qs+" a solid blow." ;
        victim = "You grunt as "+name+" deals you a solid blow."; 
        break ;
      }
      case 10..15 : {
      damstr = "You "+verb1+" "+vname+" with your "+
                     wepstr+" and hit "+qs+" hard.";
       damstr2 = name +" "+verb2+" "+vname+ " with " + 
             possessive(this_object()->query("gender"))+" "+ 
                   wepstr + " and hits "+qs+" hard.";
       victim = name+" "+verb2+" you with " + 
              possessive(this_object()->query("gender"))+" "+ 
              wepstr + " and hits you hard."; 
        break ;
      }
      case 16..20 : {
       damstr = "You "+verb1+" "+vname+" with your "+
                 wepstr+" and devastate "+qs+".";
        damstr2 = name +" "+verb2+" "+vname+ " with " + 
             possessive(this_object()->query("gender"))+" "+ 
             wepstr + " and devastates "+qs+"."; 
        victim = name+" "+verb2+" you with " + 
             possessive(this_object()->query("gender"))+" "+ 
             wepstr + " and devastates you."; 
        break ;
      }
      case 21..30 : {
        damstr = "You nearly knock the wind from "+vname+" with your powerful blow.";
        damstr2 = name+" nearly knocks the wind from "+vname+" with "+
             possessive(this_object()->query("gender"))+" powerful blow.";
        victim = name+" nearly knocks the wind from you with "+
        possessive(this_object()->query("gender"))+" powerful blow.";
        break ;
      }
      case 31..40 : {
     damstr=vname+" screams as you deal "+qs+" a crushing blow.";
        damstr2 = vname+" screams as "+name+" deals "+qs+" a crushing blow.";
        victim = "You scream as " +name+" deals you a crushing blow.";
        break ;
      }
      default : {
        damstr = "Blood flies through the air as you brutally maim "+
              vname+" with your "+wepstr+"!";
        damstr2 = "Blood flies through the air as "+name+" brutally maims "+
              vname+" with " +possessive(this_object()->query("gender"))+ 
                " "+ wepstr+ "!";
        victim = "Blood flies through the air as " +name+
                      " brutally maims you with "+vname+" with "+
                          possessive(this_object()->query("gender"))+ 
                           " " + wepstr+ "!";break;
      }
    }
        // The routines below check to see if all the listeners really
        // want to hear how the battle is going (Watcher, 4/27/93).

        if(!(this_object()->query("noise_level") && damage < 2))
         tell_object(this_object(), damstr+"\n");

        for(loop=0; loop<sizeof(contents); loop++) {
          if(contents[loop])
                noise = (int)contents[loop]->query("noise_level");

          if(noise && (noise > 1 || (noise == 1 && damage < 2)))
                continue;

          tell_object(contents[loop],
     damstr2+"\n");

        }

        if(attackers[0] &&
           !(attackers[0]->query("noise_level") && damage < 2))
        tell_object(attackers[0],
      victim+"\n");

        } else {

// If we got here, it means we missed the hit roll, or did zero damage.

  qs = subjective((string)attackers[0]->query("gender"));
        if(!this_object()->query("noise_level"))
        switch(random(11)) {
          case 0: write("You " + verb1 + " " + vname + " with your " + 
                      wepstr + ", but you miss.\n");
                break;
          case 1: write("You "+verb1+" "+vname+" with your "+
      wepstr+", but "+qs+" dodges your clumsy attack.\n");
                break;
       case 2: write("You "+verb1+" " + vname + " with your "+
     wepstr+", but "+qs+" avoids the blow easily.\n");
                break;
          case 3: write("You " + verb1 + " " + vname + " with your " + 
                            wepstr + ", but do no damage.\n");
                break;
          case 4: write(vname+" blocks your "+wepstr+
                         " and prepares to counter.\n");
                break;
          case 5: write("You " + verb1+" "+vname+", but trip and fall.\n");
                break;
          case 6: write("You " + verb1+" "+vname+" with your " + wepstr +
                   " and deal a mighty blow to empty air.\n");
                break;
    case 7: write(vname + " deflects your "+wepstr+
           ", causing you to miss!\n");
                break;
          case 8: write("You miss "+vname+" by an inch!\n");
                break;
          case 9: write("You miss "+vname+" by a mile!\n");
                break;
          default: write("You miss.\n");
                break;
        }

       damstr2=possessive(this_object()->query("gender"));
        switch(random(11)) {
          case 0: damstr = name+" "+verb2 + " " + vname + " with " +
                    damstr2 + " " + wepstr + ", but misses.\n";
                    break;
          case 1: damstr = name+" "+ verb2 + " " + vname + " with " +
                  damstr2 + " "+wepstr+", but "+qs
        +" dodges "+ damstr2+" clumsy attack.\n";break;
          case 2: damstr = name+" " + verb2 + " " + vname + " with " +
   damstr2+" "+wepstr+", but "+qs+
         " avoids the blow easily.\n";break;
          case 3: damstr =name+" " + verb2 + " " + vname + " with " 
                    +damstr2+ " "+wepstr + ", but does no damage.\n";
                break;
          case 4: damstr =vname+" blocks "+damstr2+" "+wepstr+
                         " and prepares to counter.\n";break;
          case 5: damstr =name+" "+verb2+" "+vname+
            ", but trips and falls on " + damstr2+" face.\n";break;
          case 6: damstr =name+" " + verb2+" "+vname+" with "+damstr2+" " 
                 + wepstr +" and deals a mighty blow to empty air.\n";
                break;
         case 7: damstr = vname+" deflects "+name+"'s "+wepstr+
     ", causing "+objective(this_object()->query("gender"))+" to miss.\n";break;
          case 8: damstr =name+" misses "+vname+" by an inch!\n";
                break;
          case 9: damstr =name+" misses "+vname+" by a mile!\n";
                break;
          default: damstr =name+" misses.\n";
                break;
        }
        for(loop=0; loop<sizeof(contents); loop++)
          if(contents[loop] && !contents[loop]->query("noise_level"))
          tell_object(contents[loop],
            damstr);

        switch(random(11)) {
          case 0: damstr = name+" "+verb2 + " you with " +
                    damstr2+ " " + wepstr + ", but misses.\n";
                    break;
          case 1: damstr = name+" "+ verb2 + " you with " +
                     damstr2+" "+wepstr + ", but you dodge "+damstr2
     +" clumsy attack.\n";break;
          case 2: damstr = name+" " + verb2 + " you with " +
                     damstr2+" "+wepstr+
   ", but you avoid the blow easily.\n";break;
          case 3: damstr =name+" " + verb2 + " you with " 
                    +damstr2+ " "+wepstr + ", but does no damage.\n";
                break;
          case 4: damstr = "You block "+damstr2+" "+wepstr+
                         " and prepare to counter.\n";break;
          case 5: damstr =name+" "+verb2+
               " you, but trips and falls on " + damstr2 + " face.\n";break;
          case 6: damstr =name+" " + verb2+" you with "+damstr2+" " 
                 + wepstr +" and deals a mighty blow to empty air.\n";
                break;
   case 7: damstr = "You manage to deflect "+name+"'s "+wepstr+
       ", causing " + qs + " to miss.\n";break
;
          case 8: damstr =name+" misses you by an inch!\n";
                break;
          case 9: damstr =name+" misses you by a mile!\n";
                break;
          default: damstr =name+" misses.\n";
                break;
        }
        if(attackers[0] && !attackers[0]->query("noise_level"))
       tell_object(attackers[0], damstr);
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

  foo = find_living(str);
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
  set("luck", random(5) - random(5));

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
  set("invisible", 0, OWNER_ONLY);
  set("short", "@@query_short", LOCKED);
  set("title", "@@query_title", LOCKED);
   set("cap_name", capitalize(query("name")));
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
  set("max_vol", "@@query_volume");
  set("max_cap", "@@query_capacity");
   set("armor_class", "@@query_ac");
/*
   set("volume", "@@query_volume");
   set("capacity", "@@query_capacity");
*/
   set("mass", USER_MASS) ;
   set("bulk", USER_BULK) ;
   set ("time_to_heal", 10) ;
   set("channels", "", MASTER_ONLY);
   enable_commands();
}

int remove() {
   string euid;
   mixed *inv;
   int loop;
 
   if(previous_object()) {
      euid = geteuid(previous_object());
      if( (euid != ROOT_UID) && 
          (euid != geteuid(this_object())) &&
          !member_group(euid, "admin")       ) {
         write("You may not remove other players.\n");
         return 0 ;
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
   return living::remove();
}
 
static int in_de_quit_script;

// I made this static so that people wouldnt be calling quit in each other.
//   I cant believe this wasnt already the case :)  
//  Although I suppose there is some subtle reason why it should be non
//  static like for a crash or a shutdown, but well see :)
int quit(string str) {
   object *stuff, *inv;
   int i, j;

   if (previous_object()!=this_object() &&
 			geteuid(previous_object())!=ROOT_UID) {
      return 0 ;
   }

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
//  PARTY-D->check_party(this_object());

   // Chronos' fix.
  if (this_object()->query("leader")) {
     if ((string)this_object()->query("leader") ==
         (string)this_object()->query("name")) force_me("band disband");
    else force_me("band leave");
  }
  command("endfollow");
  command("unkeep all -silent");
 
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

  // Are we busy?  We aren't anymore.. Turn off the busy flag so it's
  // not set the next time we log in.
  this_object()->delete("busy");
   // If the "harass" logging is still on, then turn it off.
   
   if (query("harass") > 0 ) {
	set("harass", 0);
	write("Harass Log turned off.\n");
   }
 
/* 
#ifdef LOGOUT_MSG
   if(previous_object() == this_object() && this_player())
	write( LOGOUT_MSG );
#endif
*/

   // If this is an invisible wizard, we let the invisibility stay on: but
   // if it's a player who cast the invisibility spell, then we want him
   // to be visible when he reappears.

   if(!wizardp(this_object()))	set("invis", 0);

   if (link) {
	link->set("last_on", time());
	link->set("ip", query_ip_name(this_object())) ;
   }
 
#ifdef QUIT_LOG
  if (query_ip_name(this_object()) == "0") 
  log_file(QUIT_LOG, query("cap_name")+"'s linkdead statue was forced to quit. ["+
    extract(ctime(time()),4,15)+"]\n");
  else
   log_file(QUIT_LOG, query("cap_name") + ": quit from " +
	    query_ip_name(this_object()) + " [" +
	    extract(ctime(time()), 4, 15) + "]\n");
#endif
  
   //   First save the user's personal data.

   save_data();

    // If this player is a wizard, move them home before dropping things.
    // If this poses a problem, we could come up with a default place to 
    //   move them.

    if (wizardp(this_object())) command("home");

   //   Then destroy autoloading inventory.

   destroy_autoload_obj();

   //   Now drop everything droppable on the user.

   inv = all_inventory( this_object() );
   inv = filter_array(inv, "inventory_check", this_object());

   if(inv && sizeof(inv))  command("drop all");
  this_object()->set("capacity", (int)query_capacity());
  this_object()->set("volume", (int)query_volume());
 
   //	Announce the departure of the user.

   if(this_object() && visible(this_object()))
   //say(query("cap_name") + " left the game.\n");
     say(LEFT_THE_GAME_MSG);
 
#ifdef LOGOUT_MSG
    if(previous_object() == this_object() && this_player())
        write( LOGOUT_MSG );
#endif
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
	if(!query("al_title"))
		set("al_title","neutral");
/*
	if(!getenv("TITLE")){
		if (!wizardp(this_player()))
			setenv("TITLE","$N the utter novice ($A)");
      else
		setenv("TITLE","$N the Wizard ($A)");
   }
  */ 
   if (!query("base_stat")) set("base_stat", query("stat"), LOCKED);
  // We make sure everyone's stats are back to normal when they log in.
   set("stat", query("base_stat"));
   set("size", query("SIZE"));
  delete("magical_defense");
   fix_volcap();
   set("time_to_heal", 10);
  this_object()->set("luck", random(5) - random(5)) ;
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
   string temp ;
 
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
      if(!(temp && stringp(temp) && move(temp) == MOVE_OK)){
	  if (wizardp(this_object()) )
   	    move(WIZ_START);
   	    else move(START);
	}
#else
		if (wizardp(this_object()) )
	     move (WIZ_START) ;
	   else move (START) ;
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
      set_temp("force_to_look", 1);
      ghost->force_me("look");
      set_temp("force_to_look", 0);
      tell_object(ghost, "\nYou suddenly realize that you are still " +
		  "a ghost.\n");
  tell_room(environment(ghost), query("cap_name") +
		" enters the game.\n", ({ ghost }));
      remove();
   return; }
 
   if(visible(this_object()))
  say(this_object()->query("cap_name") + " enters the game.\n");
 
#ifdef LOGIN_LOG
  log_file(LOGIN_LOG, this_object()->query("cap_name") + ": logged in from "+
	    query_ip_name(this_object()) + " [" +
	    extract(ctime(time()), 4, 15) + "]\n");
#endif
 
   set_temp("force_to_look", 1);
   command("look");
   set_temp("force_to_look", 0);
 
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
  say((string)this_object()->query("cap_name") +
      " suddenly turns into a marble statue!\n");
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
   say("The statue of " + query("cap_name") + 
   " slowly returns to flesh.\n");
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

  if (this_player() && this_player()!=this_object()) return ;
   tell_object(this_object(), " ");  		//  Beep em
   tell_object(this_object(), "\nSorry, you have idled too long.\n");
   tell_object(this_object(), "Selling all your stuff.. \n");

 
   if(environment()) {

   if(type == "linkdead")
tell_room(environment(), "The linkdead statue of " +
   query("cap_name")+" suddenly crumbles to the ground.\n",
	     ({ this_object() }));
    else tell_room(environment(), 
  "The idle body of "+query("cap_name") + " slowly fades from sight.\n",
   ({ this_object() }));
   }
 
   this_object()->move_player("/d/Start/town/rooms/shop", "SNEAK");
   command("sell all");
   this_object()->quit();

}
 


static void die() {
   object killer, ghost, corpse, coins, *stuff;
  mapping stat_map;
  string *stats, *names, name, saviour;
  int total_stats, i;

  i = (int)query("luck");
  if (i==5) 
  if (2>random(100)+1) {
     set("luck", random(5) - random(5));
     set("hit_points", 1);
     write("You manage to survive by the sheerest of luck!\n");
     say(TPN + " manages to survive on luck alone.\n");
      return ;
  }

   //	Set the user's killer variable
 
   killer = query("last_attacker");
   if (!killer) killer = previous_object() ;
 
   //	If the wizard has themself set to "immortal", then
   //	they cannot die ... stop death call.
 
   if(wizardp(this_object()) && query("immortal")) {
   write(@ENDHEAL
You stagger to one knee, and feel the icy grip of death surround
you.  You laugh aloud as you brush Death off like it were but a 
mere nuisance and rise again, at full strength.
ENDHEAL
 );
  message("combat", query("cap_name") + 
  " staggers to one knee for a moment.\n" +
  "You watch in amazement as " + possessive(query("gender")) + 
  " wounds heal all by themselves.\n", environment(),
  ({ this_object() }) );
  this_player()->set("hit_points", query("max_hp"));
   return; }

   //	If the user is already dead ... stop death call.
 
   if(link_data("dead"))  return ;
  if (query("dying")) return ;
  set("dying", 1);
 
   // Bail out of any parties they may be involved in.

// check_team() ;
   PARTY_D->check_party(this_object());
   command("endfollow");
   command("unkeep all -silent");
 
   //	Announce the user's death

   write("You have died.\n");
 
   say(query("cap_name") + " has died.\n", ({ this_player() }) );

// Record deaths and kills for score command. :)
  if (userp(killer)) {
    killer->add("pkills", 1);
    this_object()->add("pdeaths", 1);
  }
  killer->add("kills", 1);
  this_object()->add("deaths", 1);

//fix up the alignment.
   if (userp(killer))
         killer->add_alignment((-1*(int)query("alignment")-10)/4);

  experience -= experience / 3;

// Make them lose a level too....
   if (link->query("level")>1)
     link->set("level", (int)link->query("level")-1);

// And lose some stats....

  if (!wizardp(TP)) 
     GUILD_D->death_stat_loss(this_player());

 
   init_attack() ;
 
   //	Setup corpse with user's specifics
 
   corpse = clone_object(STANDARD_CORPSE);
 
  corpse->set("killer", killer->query("cap_name"));
  corpse->set("gender", query("gender"));
   corpse->set_name(query("cap_name")) ;
 
   i = query("mass") ;
   if (i>0) corpse->set("mass", i) ;
 
   i = query("bulk") ;
   if (i>0) corpse ->set("bulk", i) ;

   i = query_level();
   if (i>0) corpse ->set("level", i) ;
 
   corpse->move(environment(this_object()));
 
   stuff = all_inventory(this_object());
 
   for(i=0;i<sizeof(stuff);i++)
     if(!stuff[i]->query("prevent_drop") && !stuff[i]->query_auto_load())
	stuff[i]->move(corpse);
 
  if (query_coins()) {
 coins = clone_object(COINS);
   coins->set_number(query_coins());
	 if (coins) coins->move(corpse) ;
   this_object()->debit(query_coins());  // All your coins are in your
                                         // corpse now. :)
   }
 
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

  if (!wizardp(this_object())) {
    if (killer && killer->query("cap_name")) 
  shout(query("cap_name")+"'s life has been taken by "+killer->query("cap_name")+".\n");
   else shout(query("cap_name")+"'s life has been extinguished.\n");
}
 
   //	Switch user to ghost body
 
   ghost = create_ghost();
 
   if(!ghost)  return;
 
   if(killer) {
     ghost->set("killer_ob", killer);
     ghost->set("killer_name", (string)killer->query("name"));
   }
  // Move the dead guy to Death's workroom.
   ghost->move_player(DEATH_ROOM, "SNEAK");
 
   //  Use a call_out to make sure all the above calls have 
   //  completed their required processing (so we don't lose
   //  this_object() before everything is done).
 
   call_out("remove", 0);
 
}

string query_short() {
 
   if (!query("name")) return "Noname";
   if(query("name") == "noname")  return "Noname";
 
    if (!interactive(this_object()))
  return ("a marble statue of " + (string)query("title"));
 
  else 
  return (string)query("title");
}

string query_title() {
  string str, foo;
 
   str = getenv( "TITLE" );
   if (!str) str = "$N the utter novice ($A)";
   if (!sscanf(str, "%s$N%s", foo,foo))
		str=query("cap_name")+" "+str;
	else str=substr( str, "$N", query("cap_name"));
   if (sscanf(str, "%s$A%s", foo,foo ))
                 str = substr(str, "$A", query("al_title"));
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

int query_level() {
  object link;
  link = query_link();
  if(link) {
      if (member_group(this_object()->query("name"), "admin"))
               return ADMIN_LEVEL;
else
      if (member_group(this_object()->query("name"), "arches"))
         return ARCH_LEVEL;
else
     if (link->query("wizard")) return WIZARD_LEVEL;
     if (link->query("level")<1) return 1;
    else return link->query("level");
  }
  return -1;
}  
 
void autokill() {
  if (query("autokill")) command(query("autokill"));
}
/* EOF */
