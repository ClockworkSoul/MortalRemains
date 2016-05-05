// Dispater originally coded by Ilzarion. Redone completely by Cyanide

#include <mudlib.h>
#include "baator.h"

inherit MONSTER ;

void create () {
    object ob1;

    ::create() ;
    seteuid(getuid()) ;
    set("short", "Dispater, the Archduke of Dis");
    set ("long", @EndLong
Dispater, the Lord of Dis, is tall and sophisticated looking, dressed in a
professional looking navy blue suit; he has two subtle horns, a thin tail
and hooves, but looks mostly human.
EndLong
    );
    set ("id", ({ "dispater", "lord", "baatezu"}) ) ;
    set_name ("dispater") ;
    set("author", "cyanide");
    set("time_to_heal", 2) ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    enable_commands() ;
    set_living_name("dispater") ;
    set ("stat/constitution", 20);
    set ("stat/strength", 20);
    set ("stat/charisma", 22);
    set ("stat/intelligence", 24);
    set ("stat/dexterity", 19);
    set ("stat/wisdom", 22);    
    set_size(7);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set ("damage", ({ 1,8 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set ("weap_resist", 3);
    set("magic_resist", 70);
    set("mage_spells", ({ "fireshield", "bolt", "wilting",
      "stoneskin", "summon7", "summon8", "summon9" }) );
    set ("max_sp", 2500);
    set ("spell_points", 2500);
    set ("resist_type", ([ "cold" : 0, "poison" : 0, "fire" : 0 ]) );
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
    ob1 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob1->delete("short");
    ob1 -> move (this_object()) ;

    set_skill("Staves", 3, "strength");
    arm(BAATOR+"items/disstaff.c");
    set("prevent_summon", 1);
    set ("special", 15);
    set_level(35);
}

void init(){
    ::init();

    force_me("cast summon"+(random(2)+7));
    force_me("cast fireshield cold");
}


void special_attack() {
    string name;
    int num;

    num = sizeof(attackers);
    name = (attackers[ random(num) ] -> query("id"))[0];

    if (query("power_delay")) {    
	force_me("say Fear the lords of the pit foolish mortal, go no further!");
    } else {
	switch( random(9) ) {
	case 0..1 : command("cast bolt at "+name); break;
	case 2 : command("cast wilting at"+name); break;
	case 3..5 : command("cast summon7"); break;
	case 6..7 : command("cast summon8"); break;
	case 8 : command("case summon9"); break;
	}
    }
}


/* EOF */
