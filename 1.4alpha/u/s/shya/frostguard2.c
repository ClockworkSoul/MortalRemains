

#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set ("short", "Frost Guard");
    set ("long", "This guard is one monsterous block of ice.\n");
    set ("id", ({"guard", "frost guard", "frostguard"}) );
    set_name("frost guard");
    set ("gender", "male") ;
    set ("race", "troll");
    set ("prevent_summon", 1);
    enable_commands() ;
    set ("chat_chance", 5);
    set ("chat_output", ({
         "The guard stares at you with a frozen stare.\n",
	   "The guard shouts, 'Halt! Who goes there?'\n",
       }) );
    wear("/d/Arctic/Shya/weapons/frostshield.c");
arm("/d/Arctic/Shya/weapons/frozenaxe.c");

}
