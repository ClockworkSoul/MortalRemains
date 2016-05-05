// By Ilzarion.

#include <mudlib.h>
#include "baator.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Amduscias") ;
    set ("long", @EndText
This is Amducias, Duke of Lord Bel, a leader of several companies of 
abishai. He appears to you as a hawk-headed man wearing dark red or black
robes. He is known to be a being of long memory and cunning strategies.
EndText
    );
    set ("id", ({ "amduscias", "duke", "baatezu"}) ) ;
    set_size(8);
    set("author", "ilzarion");
    set_name ("amduscias") ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    enable_commands() ;
    set_align("le");
    set_living_name("amduscias") ;
    set("stat", ([
      "constitution" : 22,
      "strength" : 23,
      "charisma" : 20,
      "intelligence" : 18,
      "dexterity" : 20,
      "wisdom" : 15,
    ]) );
    set("base_ac", -2);
    set ("armor_class", -2);
    set("natt", 6);
    set ("damage", ({ 5,15 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "warrior");
    set ("class", "fighter");
    set ("weap_resist", 2);
    set ("magic_resist", 65);
    set ("resist_type", ([ "cold" : 50, "poison" : 0, "fire" : 0 ]) );

    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;

    set_skill("Short Blades", 5, "Strength") ;
    set_skill("Two Weapon Style", 2, "Strength") ;
    set_skill("Ambidexterity", 1, "Strength") ;

    arm(BAATOR+"items/blackblade.c");
    arm(BAATOR+"items/blackblade.c");

    set("prevent_summon", 1);
    set_level(21);  
}

