/*
** Done by Nightmask with a little help from Cyanide.
** 30 Sep 97 - Cyanide fixed a damage type error and neatened Ilzarion's
**    LAZY code.  ;)
**  8 Oct 97 - It would appear Ilzarion added weapon + restrictions?
**    Cyanide did this header.
**  9 Oct 97 - Cyanide fixed a logic bug in Ilz's previous fix. No biggie.
** March sometime, Nightmask changed a few variables and created a
** new command for a class he designed. All pervious changes had been
** left, nothing major was done to the original format.
** Again, special thanks to Cyanide dor getting the original working.
** 01 Jun 2000  Chronos revamps this entire thing, keeping alot of the
**              original code.
*/
#include <mudlib.h>
#include "checkob.h"

inherit DAEMON;

int cmd_headshot(string targ) {
    object ob, weapon, hdst;
    int *dmj, dmin, dmax, damage;
    int multiplier, hit;
    int level;
    string type;
    if (TP->query_level() < 7) {
	write("You are not yet skilled enough to do this.\n");
	return 1;
    }
    if (!checkob(TP)) return 1;
    if (!targ) {
	write("You must specify a target for a headshot.\n");
	return 1;
    }
    targ = lower_case(targ);
    if (targ==TPn) {
	write("Commit suicide?  Use the \"suicide\" command.\n");
	return 1;
    }
    if (environment(TP) && environment(TP)->query("safe")) {
	write("You are in a safe area. You can't do that here.\n");
	return 1;
    }

    switch((int)TP->query("handedness")) {
    case 1: weapon=TP->query("weapon2") ;
	if (!weapon) weapon=TP->query("weapon1") ;
	break ;
    default: weapon=TP->query("weapon2") ;
	if (!weapon) weapon=TP->query("weapon1") ;
	break ;
    }
    if (!weapon) {
	write("You must have a weapon wielded to do that.\n");
	return 1;
    }
    if ((string)weapon->query("weapon_type") == "Machine Weapons") {
	write("You can't go for a headshot with a Machine Gun.\n") ;
	return 1;
    }
    if ((string)weapon->query("weapon_type") != "Long Arms"  &&
      (string)weapon->query("weapon_type") != "Small Arms") {
	write("You must be using a gun to try for a headshot.\n");
	return 1;
    }
    dmj = weapon->query("damage");
    type = weapon->query("damage_type");
    ob = present(targ, environment(this_player()));

    if (!ob) { 
	write("Cannot locate that target.\n") ;
	return 1;
    }

    if (!living(ob)) {
	write ("That is an inanimate object.\n");
	return 1;
    }

    if (ob->query("no_attack")) {
	write("You are not permitted to attack that.\n") ;
	return 1;
    }

    hdst = present("#HEADSHOT#", ob);
    if (hdst) {
	if (member_array((string)this_player()->query("name"),
	    (string *)hdst->query("headshoted")) == -1) {
	    hdst->add("headshoted", ({ this_player()->query("name") }) );
	} else {
	    write(ob->query("cap_name")+" is wary of you now...\n");
	    return 1;
	}
    } else {
	hdst = clone_object("/d/class/warrior/Sharpshooter/obj/headshot.c");
	if (!hdst) {
	    write("Something is wrong..\nYour hands are shaking...\n.. can't aim..\nYou feel like you should notify Chronos.\n");
	    return 1;
	}
	hdst->set("headshoted", ({ this_player()->query("name") }) );
	hdst->move(ob);
    }
    level = TP->query_level();
    dmin = dmj[0]; dmax = dmj[1];
    damage = random(1 + dmax - dmin) + dmin;
    switch (level) {
    case 0 : break;
    case 7..20: multiplier = 2; break ;
    case 21..35: multiplier = 3; break ;
    default: multiplier = 4; break ;
    }
    /* What is this ??
	if (present("#HDST#", this_player())) {
	    for(dmin=0;dmin<sizeof(all_inventory(TP));dmin++) {
		dmax = all_inventory(TP)[dmin]->query("hdst_mult");
		if (dmax) multiplier += dmax;
	    }
	}
    */
    damage*=multiplier;  

    damage+=(int)weapon->query("dam_adj");
    damage+=(int)weapon->query("temp_dam_adj");
    hit = 4;
    hit+=(int)weapon->query("temp_to_hit");
    hit+=(int)weapon->query("to_hit_adj");
    say(wrap(TPN+" suddenly draws "+possessive(TP->query("gender"))+
	" "+weapon->query("name")+" and fires a shot straight at "+
	ob->query("cap_name")+"'s head!"), ({ TP, ob }) ); 
    write(wrap("You draw your "+weapon->query("name")+" and fire a shot right at "+
	ob->query("cap_name")+"'s head with deadly precision.") ) ;
    if (TP->query_hit(ob, hit)) {              // Did we hit ?
	dmin = ob->query("weap_resist");
	if (!dmin) dmin = 0;
	dmax = (weapon->query("enchantment"));
	if (!dmax) dmax = 0;
	if (weapon->query("hit_func"))
	    damage = (weapon->hit_func(ob, damage));
	if (dmax<=weapon->query("bonus")) {
	    if (damage <= ob->query("hit_points")) {
		write("You critically hit "+ob->query("cap_name")+"'!\n");
		say(TPN+" critically hits "+ob->query("cap_name")+"'!\n",
		  ({ ob, TP }) ) ;             
		tell_object(ob, @ENDHIT
You feel extreme pain as a bullet tears through your head!
You fight through the pain and the desire to blackout and turn towards
your assailant.
ENDHIT
		) ;
	    } else {
		write("You plant one right between "+ob->query("cap_name")+"'s eyes!\n");
		write("You watch with satisfaction as "+subjective(ob->query("gender"))+
		  " slumps to the ground and twitches.\n") ;
		say(TPN+" plants one right between "+ob->query("cap_name")+"'s eyes!\n"+
		  ob->query("cap_name")+" slumps to the ground, twitching slightly.\n",
		  ({ ob, TP }) ) ;             
		tell_object(ob, @ENDHIT
You feel a slight pain as a bullet enters your skull right between the eyes.
Your vision goes red and you feel disoriented...
ENDHIT
		) ;
	    }
	    damage = ob->receive_damage(damage, type, TP, 1);
	    TP->ammo_debit(type,1);
	    ob->set("last_attacker", TP);
	} else {
	    write("Your bullet ricochets off "+ob->query("cap_name")+"!\n");
	    write("You realize, with dismay, that your weapon is useless against "+
	      objective(ob->query("gender"))+".\n") ;
	    tell_object(ob, "Suddenly, a bullet ricochets off your head!\n") ;
	    say(TPN+"'s bullet simply ricochets off "+ob->query("cap_name")+
	      "'s head!\n", ({ ob, TP }) ) ;
	}
    } else {
	write("You can't believe it!  You missed!\n");
	tell_object(ob,@ENDMISS
You hear the click of a gun behind you and move just in time to avoid certain death.
ENDMISS
	) ;
	tell_object(ob, wrap("You spin around suddenly to find "+TPN+
	    " standing before you with smoke curling from "+
	    possessive(TP->query("gender"))+" "+weapon->query("name")+".")) ;
	say(wrap(ob->query("cap_name")+
	    " moves just in time to avoid the shot and spins around to face "+
	    TPN+"!"), ({ TP, ob }) ) ;
    }
    ob->kill_ob(TP);
    return 1;
}         
/* EOF */
