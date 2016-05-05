// Coded by Ilzarion
// Fixed by Cyanide - 11/26/1998, and agian 6/11/00.

#include "baator.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "barbazu") ;
    set ("long", @EndLong
The barbazu, also called the "bearded devil" is a foul, humanoid creature
with a long tail, clawed hands and feet, pointed ears, and a snaky,
disgusting beard. Its skin is moist, though scaly like a reptile. They are
low-ranking among the baatezu, and tend to serve as their shock troops.
EndLong
    );
    set ("id", ({ "barbazu", "baatezu" }) ) ;
    set("stat", ([
      "strength" : 16,
      "constitution" : 15,
      "dexterity" : 15,
      "intelligence" : 16,
      "wisdom" : 9,
      "charisma" : 4
    ]) );
    set_align("le");
    set_name ("barbazu") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    set_size(6);
    enable_commands() ;
    set_living_name("barbazu") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 30);
    set("weap_resist", 1);
    set ("base_ac", 3);
    set ("armor_class", 3);
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;

    set_skill("Polearms", 2, "Strength") ;
    set_skill("Two Handed Style", 2, "Strength");
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(BAATOR+"items/woundglaive.c"),

    set_level(8);
}

/* EOF */


