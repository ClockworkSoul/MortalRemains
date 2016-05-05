

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
    enable_commands() ;
    set_living_name("frost guard");
    set ("stat/constitution", 40);
    set ("stat/strength", 24);
    set ("base_ac", 0);
    set ("armor_class", -1);
    set ("damage", ({ 5,15 }) ) ;
    set ("weapon_name", "frozen axe");
set ("armour_name", "frost shield");
    set ("CLASS", "warrior");
    set_verbs( ({ "smashes at", "swings at", "swipes at" }) ) ;
    set ("weap_resist", 3);
    set("resist_type", ([ "fire":0 ]));
    set("magic_resist", 500);
    set_size(12);
    set_level(20);
    set ("moving", 0);
    set ("speed", 10);
    set ("chat_chance", 10);
    set ("chat_output", ({
         "The guard stares at you with a frozen stare.\n",
	   "The guard shouts, 'Get out now!'\n",
         "The guard shouts, 'Leave this place or get hurt!'\n"
       }) );
    set ("att_chat_output", ({
         "The guard glares at you with a frosty look.\n",
       }) );
wear("/d/Arctic/Shya/weapons/frostshield.c");
arm("/d/Arctic/Shya/weapons/frozenaxe.c");

}
