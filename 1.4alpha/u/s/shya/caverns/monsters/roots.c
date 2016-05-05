#include "../cavern.h"

inherit MONSTER;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("alt_corpse", MONSTERS "/roots-corpse.c");
    set("author", "shya");
    set ("short", "Roots");
    set ("long", "Millions of tiny roots block the entrance.\n");
    set ("id", ({"roots"}) );
    set_name("roots");
    set ("race", "roots");
    enable_commands() ;
    set_living_name("roots");
    set ("stat/constitution", 9);
    set ("stat/strength", 11);
    set ("base_ac", -1);
    set ("armor_class", -2);
    set ("damage", ({ 1,3 }) ) ;
    set_verbs( ({ "entangles" }) ) ;
    set ("weap_resist", 1);
    set_size(3);
    set_level(2);
    set ("moving", 0);
    set ("speed", 10);
    set ("chat_chance", 10);
    set ("att_chat_output", ({
         "The roots reach out to try to entangle you.\n",
       }) );
}
