// Coded by Ilzarion.
// Cyanide fixed it.

#include "baator.h"
#include <messages.h>

inherit BAATOR+"monsters/pit_fiend.c";

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("short", "Gazra, Fierana's General");
    set("long", @EndText
This unusually large pit fiend serves Fierana as the general of her armies.
EndText
    );
    set("id", ({"gazra", "pit fiend" }));
    set_name("gazra");
    set_living_name("gazra");
    set("author", "cyanide");
    set_size(12);
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 50);
    set("weap_resist", 3);
    set("stat/strength", 24);
    set ("base_ac", -5);
    set ("armor_class", -5);
    set("prevent_summon", 1);
    set_level(30);
}
