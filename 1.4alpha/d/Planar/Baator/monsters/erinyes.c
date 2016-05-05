#include "baator.h"
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "erinyes") ;
    set ("long", @EndText
The erinyes looks like a beautiful human female with huge, feathery wings
and pointed ears. 
EndText
    );
    set ("id", ({ "erinyes", "baatezu" }) ) ;
    set_size(6);
    set_name ("erinyes") ;
    set ("race", "baatezu");
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("erinyes") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 30);
    set("weap_resist", 1);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_skill("Whips", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(BAATOR+"items/entanglewhip.c");
    set_level(7);
}
