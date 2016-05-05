#include "abyss.h"
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Alu-Fiend") ;
    set ("long", "A female half-fiend.\n") ;
    set ("id", ({ "alu fiend", "alu-fiend", "tanar'ri" }) ) ;
    set_size(5);
    set_name ("alu-fiend") ;
    set ("race", "tanar'ri");
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("alu-fiend") ;
    set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
    set("magic_resist", 30);
    set("weap_resist", 1);
    //set("stat/strength", 20);
    set ("base_ac", 5);
    set ("armor_class", 5);
    set("natt", 1);
    set("CLASS", "warrior");
    set ("damage", ({ 2,12 }) ) ;
    set ("weapon_name", "claws") ;
    set_skill("Long Blades", 1, "Strength") ;
    set_skill("Two Handed Style", 2, "Strength");
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set_level(2);
    arm(ABYSS+"items/2hsword2.c");
}
