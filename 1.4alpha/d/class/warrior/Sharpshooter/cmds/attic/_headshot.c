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
*/

inherit DAEMON;

#include <daemons.h>
#include <mudlib.h>

int cmd_headshot(string targ) {
    object ob, weapon, hdst;
    int *dmj, dmin, dmax, damage;
    int multiplier, hit;
    int level;
    string type;

    if (!targ) {
	write("Shoot who in the head?\n");
	return 1;
    }
    if(TP->query_level() < 45) {
	write("You are not yet skilled enough to do this.\n");
	return 1;
    }


    if (targ == TP->query("name"))
    {
	write("Your a fucking bumbass, huh?\n");
	return 1;
    }

    weapon = (object)this_player()->query("weapon"+
      (this_player()->query("handedness")));

    if (!weapon) {
	write("You plan to hit him with a ruubber band? Wield your gun!.\n");
	return 1;
    }


    if (!weapon) {
	write("What you got a peashooter, use your gun dipshit.\n");
	return 1;
    }

    if ((string)weapon->query("weapon_type") != "Long Arms") {
	write("You can't use that gun, try a rifle or somthing.\n");
	return 1;
    }

    dmj = weapon->query("damage");
    type = weapon->query("damage_type");
    ob = present(targ, environment(this_player()));

    if (!ob) {
	write("There's nothing there to shoot in the head.\n");
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

    hdst = present("HEADSHOTED", ob);
    if (hdst) {
	if (member_array((string)this_player()->query("name"),
	    (string *)hdst->query("headshoted")) == -1) {
	    hdst->add("headshoted", ({ this_player()->query("name") }) );
	} else {
	    write(ob->query("cap_name")+" is wary of you now...\n");
	    return 1;
	}
    } else {
	hdst = clone_object("/d/class/warrior/Sharpshooter/obj/HEADSHOTED.c");
	if (!hdst) {
	    write("Your skills fail you.  Notify Nightmask.\n");
	    return 1;
	}
	hdst->set("headshoted", ({ this_player()->query("name") }) );
	hdst->move(ob);
    }

    level = TP->query_level("sharpshooter");
    dmin = dmj[0]; dmax = dmj[1];

    //write("range: "+dmin+" to "+dmax+"\n");
    //write("type: "+type+"\n");
    damage = random(1 + dmax - dmin) + dmin;

    //write("Rolled: "+damage+"\n"); 

    multiplier = 0;

    //write("level="+level+"\n"); 

    switch (level) {
    case 0 : break;
    case 45..55 : multiplier+=30;break;
    case 56..65 : multiplier+=40;break;
    case 66..75 : multiplier+=50;break;
    case 76..85 : multiplier+=60;break;
    case 86..95 : multiplier+=70;break;
    case 96..97 : multiplier+=80;break;
    case 98..99 : multiplier+=90;break;
    default : multiplier+=100;break;
    }


    //write("Mult 1: "+multiplier+"\n"); 

    if (present("#HDST#", this_player())) {
	for(dmin=0;dmin<sizeof(all_inventory(TP));dmin++) {
	    dmax = all_inventory(TP)[dmin]->query("hdst_mult");
	    if (dmax) multiplier += dmax;
	}
    }

    damage*=multiplier;
    //ilz puts in criticals cause it seems to be missing
    //write("b4 crit: "+damage+"\n");  

    if (random(20) == 0) damage *= 2;

    //write("after crit: "+damage+"\n"); 

    damage+=PROPERTY_D->query_str_dam(this_player());
    damage+=(int)weapon->query("dam_adj");
    damage+=(int)weapon->query("temp_dam_adj");
    hit = 4;
    hit+=(int)weapon->query("temp_to_hit");
    hit+=(int)weapon->query("to_hit_adj");

    //write("After stuff: "+damage+"\n");  


    if (this_player()->query_hit(ob, hit)) {                                                     

	dmin = ob->query("weap_resist");
	if (!dmin) dmin = 0;
	dmax = (weapon->query("enchantment"));
	if (!dmax) dmax = 0;

	if (dmax >= dmin){    

	    if (damage <= ob->query("hit_points")) {
		tell_object(ob, TPN+" aims at your head and fires.\n");
		write("You sucessfully shoot "+ob->query("cap_name")+" in the head.\n");
		say(TPN+" aims and fires at "+ob->query("cap_name")+"'s head"
		  +" with their gun", ({ ob, this_player() }) );
	    } else {
		write("You decimate "+ob->query("cap_name")+" with a bullet to the head.\n");
		tell_object(ob, wrap("You feel pain as a bullet enters your head.\n"));
		say(wrap(TPN+" stands behind "+ob->query("cap_name")+" with a"
		    +" smoking gun, "+subjective(ob->query("gender"))+
		    " slumbs to the floor."), ({ TP,ob }) );
	    }
	    //Ilz is putting in a hit function now (april 11th 98)
	    if (damage) {
		if (weapon->query("hit_func"))
		    damage = (weapon->hit_func(ob, damage));
		damage = ob->receive_damage(damage, type, this_player(), 1);
	    }
	    if(TP->ammo_debit(type,1));

	    //write("If this number is 0: ----> "+damage+"\n"+
	    // "The prob is the damage type or receive damage.\n");

	    ob->set("last_attacker", this_player());
	    ob->kill_ob(this_player());

	} else {
	    write("Your weapon is useless against "+ob->query("cap_name")+"!\n");
	}

	ob->kill_ob(this_player());

    } else {
	write("You miss!\n");
	tell_object(ob,wrap("You are surprised to see a bullet pass within "+
	    " inches of you!"));
	say(wrap(TPN+" fires a shot at "+
	    ob->query("cap_name")+" and misses."), ({ TP, ob }) );                 
	ob->kill_ob(this_player());
    }

    return 1;
}

/* EOF */
