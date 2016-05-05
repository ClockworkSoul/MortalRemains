// DOne by Ilzarion
// Cyanide SERIOUSLY cut back on the damage it does. 2 Mar 2000

inherit DAEMON;

#include <daemons.h>
#include <mudlib.h>


int cmd_deathblow(string targ) {
    object ob, weapon, bksb;
    int *dmj, dmin, dmax, damage;
    int multiplier;
    int level;   //Forgot this, too.
    string type;

    if ((this_player()->query_skill("Death Blow"))<1){
	write("You must have the proficiency first!\n");
	return 1;
    }


    if (!targ) {
	write("Deathblow what?\n");
	return 1;
    }

    weapon = (object)this_player()->query("weapon"+(this_player()->query("handedness")));

    if (!weapon) {
	write("You can't Death Blow with your bare hands!\n");
	return 1;
    }

    if (!environment(TP) || environment(TP)->query("safe")) {
	write("You can't do that here.\n");
	return 1;
    }

    type = (string)weapon->query("damage_type");

    dmj = weapon->query("damage");
    ob = present(targ, environment(this_player()));

    if (!ob) {
	write("There's nothing by that name to deathblow.\n") ;
	return 1;
    }    

    if (!living(ob)) {
	write ("That's not alive!\n");
	return 1;
    }
    if (ob->query("no_attack")) {
	write("You are not permitted to attack that.\n") ;
	return 1;
    }    

    bksb = present("DEATHBLOWED", ob);

    if (bksb) {
	if (member_array((string)this_player()->query("cap_name"),
	    (string *)bksb->query("deathblowed")) != -1) {
	    bksb->add("deathblowed", ({ this_player()->query("name") }) );
	} else {
	    write(ob->query("cap_name")+" is watching for those tactics again...\n");
	    return 1;
	}
    } else {
	bksb = clone_object("/d/class/warrior/obj/DEATHBLOWED.c");
	if (!bksb) {
	    write("Your skills fail you.  Notify Ilzarion.\n");
	    return 1;
	}
	bksb->set("deathblowed", ({ this_player()->query("name") }) );
	bksb->move(ob);
    }

    TP->block_attack(1);
    level = TP->query_level("warrior");
    dmin = dmj[0]; dmax = dmj[1];

    damage = random(1 + dmax - dmin) + dmin;

    // write("Rolled: "+damage+"\n");
    //  damage*=multiplier;


    if (random(20) == 0) damage *= 2;

    //write("after crit: "+damage+"\n");

    damage+=PROPERTY_D->query_str_dam(this_player());

    if (!ob->save_throw()){
	if (this_player()->query_level() > ob->query_level()){
	    damage *= 10;
	}
    }

    if (this_player()->query_hit(ob)){   

	dmin = ob->query("weap_resist");
	dmax = (weapon->query("enchantment")+1);

	if (dmax > dmin){    
	    if (damage <= ob->query("hit_points")) {
		tell_object(ob, TPN+" Attempts to do away with you in one blow!.\n"
		);
		write("You fail to kill your target in one blow.\n");
		say(TPN+" Attempts to death blow "+ob->query("cap_name")+".", ({ ob, this_player() }) );
	    } else {
		write("You slay "+ob->query("cap_name")+" in one blow!\n");
		tell_object(ob,wrap("You are set upon swifty and killed."));
		say(wrap(TPN+" Rends "+ob->query("cap_name")+" into gore."), ({ TP, ob }) );

	    }

	    ob->receive_damage(damage, type, this_player(), 1);
	    ob->set("last_attacker", this_player());
	    ob->kill_ob(this_player());
	    return 1;
	}else{
	    write("You weapon is useless against "+ob->query("cap_name")+"!\n");
	    ob->kill_ob(this_player());
	    return 1;
	}

    }else{

	write("You miss!\n");
	tell_object(ob,wrap("You are surprised to see a blade pass within inches of you!"));
	say(wrap(TPN+" Attempts to kill "+
	    ob->query("cap_name")+" in one blow!, and misses."), ({ TP, ob }) );                 
	ob->kill_ob(this_player());
	return 1;
    }
}
