// Created by Cyanide to fuck with players.

#include <mudlib.h>
#include <move.h>
#include "monsters.h"
#include "/u/c/cyanide/debug.h"

void steal_something();

inherit MONSTER ;

object body;
int c = 0, flag;

void create () {
    object belt, wep;

    ::create();
    seteuid(getuid()) ;

    set("prevent_summon", 1);
    set("short", "a seedy looking man") ;
    set("long", @EndLong
A scruffy looking man with dirty clothing and several day's 
worth of beard growth. He doesn't strike you as a very nice 
person.
EndLong
    );

    set("id", ({"man", "thief", "individual"}));
    set_size(6);

    set("author","cyanide");
    set_name ("seedy-looking man");
    set_living_name("Individual");
    enable_commands() ;

    set("stat", ([
      "strength" : 14,
      "intelligence" : 18,
      "dexterity" : 24,
      "constitution" : 14,
      "charisma" : 12
    ]) );

    set ("gender", "male") ;
    set ("race", "human");
    set_align("ce");

    set ("damage", ({ 1, 7 }) ) ;
    set ("weapon_name", "fists");
    set ("damage_type", "bludgeoning");
    set_verbs( ({ "maul" , "crush", "pummel" }) );
    set_verbs2( ({ "mauls", "crushes", "pummels" }) );

    set("wimpy", 45);
    set("pursuing",1);
    set("moving", 1);

    set_skill("Short Blades", 4, "strength");
    set_skill("Unarmed", 4, "strength");
    set_skill("Evasion", 1, "dexterity");

    set("CLASS", "rogue");
    set("class", "thief");

    belt = clone_object("/d/class/rogue/std/obj/belt.c");
    belt->move(TO);
    wep = clone_object(OBJ+"/a_sword");
    wep->move(TO);

    wear(OBJ+"/th_cloak.c", "cloak");
    wear(OBJ+"/th_armor.c", "leather");

    credit( random(5000) + 3000 );
    set("special", 10);
    set_level(25);
}

void init() {
    ::init();
    command("wield sword");
}

void heart_beat() {
    flag = 0;

    heal_up();
    continue_attack();
    unblock_attack();

    if (!random(10)) command("Hide");

    if (++c >= 5) {
	steal_something();
	c = 0;
    }

    if (!flag) move_around();
}


void steal_something() {
    object *obs = ({}), ob;
    string name = query("cap_name");
    int val;

    if (environment(TO));
    obs = all_inventory(environment(TO));
    obs = filter_array(obs, "filter_obs", TO);

    if (!random(3) && sizeof(obs)) {
	ob = obs[random(sizeof(obs))];
	if (!living(ob)) {
	    // If the thief finds cash, he might add some,
	    // take some, or take it all.  ;)
	    if (ob->query("money")) {
		DEBUG("CASH!  ");
		val = ob->query_number();
		if (!random(3)) {
		    DEBUG("Takes all\n");
		    command("get "+val+" credits");
		} else {
		    val = (random(val) - (val/2));
		    if (val > 0) {
			DEBUG("Drops "+val+"\n");
			command("drop "+val+" credits");
		    } else {
			val*=-1;
			DEBUG("Takes "+val+"\n");
			command("get "+val+" credits");
		    }
		}
	    } else {
		// Otherwise he'll just fiddle around with the 
		// stuff.
		ob->add("id", ({ "M" }) );
		command("do get M, put M in bag");
	    }
	} else {
	    object item;
	    obs = all_inventory(ob);
	    obs = filter_array(obs, "filter_obs", TO);
	    if (sizeof(obs)) {
		item = obs[random(sizeof(obs))];
		if (item->move(TO)==MOVE_OK)
		    tell_object(ob, "Your pack feels lighter.\n");
	    } else {
		command("backstab "+((string*)ob->query("id"))[0]);
	    }
	}
    } else {
	if (!sizeof(obs)) {
	    obs = all_inventory(TO);
	    obs = filter_array(obs, "filter_to_drop", TO);
	    command ("drop M "+(random(sizeof(obs))+1));
	}
    }
}

int filter_obs (object ob) {
    if (userp(ob) && visible(ob, TO)) flag = 1;
    if (!ob->query("short")) return 0;
    if (!visible(ob, TO)) return 0;
    if (ob == TO) return 0;
    if (ob->query("prevent_drop")) return 0;

    return !((int)ob->query("prevent_get"));
}

int filter_to_drop ( object ob ) { return ob->id("M"); }

/* EOF */
