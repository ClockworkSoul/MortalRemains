// By Ilzarion.
// Cleaned by Cyanide, 11/26/1998 11:44:19 PM 

#include <mudlib.h>
#include "baator.h"

inherit MONSTER ;

static object ob1, ob2;

void create () {
    object tmp;

    ::create() ;
    seteuid(getuid()) ;
    set("short", "Bel, Lord of the First");
    set ("long", @EndBel
Bel takes the form of a burly humanoid with a jutting chin and powerful 
arms. His skin is slightly tinged with red. His brooding scowl and the 
promise of rage held barely in check dissuades many from offending the
Lord of the First.
EndBel
    );
    set("lore", wrap(
	"Bel is the newest of the Nine Lords of Baator, having only recently "+
	"wrested the position from the previous Lord. Legend has it, his "+
	"twin axes can cleave a man in two on their own accord, so powerful "+
	"is their enchantment; in addition, they are attuned to the life "+
	"force of their owner, and cease to exist upon his death.") );
    set ("id", ({ "bel", "lord", "baatezu"}) ) ;
    set_size(8);
    set("author", "cyanide");
    set_name ("bel") ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    enable_commands() ;
    set_align("le");
    set_living_name("bel") ;
    set("stat", ([
      "constitution" : 21,
      "strength" : 24,
      "strength" : 24,
      "charisma" : 20,
      "intelligence" : 18,
      "dexterity" : 22,
      "wisdom" : 15
    ]) );
    set ("base_ac", 4);
    set ("armor_class", 4);
    set ("damage", ({ 10,25 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "warrior");
    set ("class", "fighter");
    set ("weap_resist", 4);
    set ("magic_resist", 75);
    set ("resist_type", ([ "cold" : 50, "poison" : 0, "fire" : 0 ]) );

    set_skill("Axes", 5, "Strength") ;
    set_skill("Two Weapon Style", 2, "Strength") ;
    set_skill("Ambidexterity", 1, "Strength") ;

    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;

    credit(5000+random(5000));

    set_level(40);

    if (ob1) {
	tmp = environment(ob1);
	if (living(ob1)) 
	    tell_object(tmp, "Bel recalls his axe to aid him.\n");

	ob1->move(this_object());
    } else {    
	ob1 = clone_object(BAATOR+"items/molyaxe") ;
    }

    if (ob2) {
	tmp = environment(ob2);
	if (living(ob1)) 
	    tell_object(tmp, "Bel recalls his axe to aid him.\n");

	ob1->move(this_object());
    } else {    
	ob2 = clone_object (BAATOR+"items/molyaxe") ;
    }

    ob1 -> move(this_object()) ;
    ob2 -> move(this_object()) ;
    ob1 -> set("wielded", 1);
    ob2 -> set("wielded", 2);
    set("weapon1", ob1);
    set("weapon2", ob2);

    set("prevent_summon", 1);
}


/* End of file */
