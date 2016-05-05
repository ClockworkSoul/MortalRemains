
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "abyss.h"

inherit MONSTER ;


void create () {

    object ob1, ob2 ;

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Babau") ;
    set ("long", "A skeletal, leathery fiend.\n") ;
    set ("id", ({ "babau", "tanar'ri" }) ) ;
    set_size(7);
    set_name ("babau") ;
    set ("race", "tanar'ri");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("babau") ;
    set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
    set("magic_resist", 50);
    set("weap_resist", 1);
    set("stat/strength", 20);
    set ("base_ac", -3);
    set ("armor_class", -3);
    set("natt", 1);
    set("CLASS", "warrior");
    set ("damage", ({ 2,12 }) ) ;
    set ("weapon_name", "claws") ;
    set_skill("Polearms", 3, "Strength") ;
    set_skill("Two Handed Style", 2, "Strength");
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set("special", 1);
ob1 = clone_object(ABYSS+"items/2hapear2.c");
    if (ob1) ob1 -> move (this_object()) ;
    set_level(11);
}

void init(){
    ::init();
    command("wield spear");
}

