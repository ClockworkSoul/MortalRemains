/*
**File: sargent.c
*/

#include "nazi.h"
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "nsd");
    set("prevent_summon", 1);
    set("ammo", ([ "12mm" : 200 ]) );
    set("short", "Storm Trooper Sergeant");
    set ("long", @EndText
A foot soldier of the NAZI movement. Loyal and harmful.
EndText
    );
    set("id", ({ "storm trooper sergeant", "sergeant", "demon", "nazi"}) );
    set_size(6);
    set_name("nazi sergeant");
    set("gender", "male");
    set("race", "demon");
    set("undead", 1);
    set("lore_type", "demon lore");
    set("damage", ({9, 16}) );
    set("damage_type", "fire");
    set("weapon_name", "machine gun");
    set_verbs( ({ "attack", "shoot", "swing at", "peer at"}) ) ;
    set("nat", 1);
    set("chat_chance", 25);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set("patrol", ({ "north", "south", "east", "west" }) );

    set("wealth", 200);
    arm(NAZI_OBJ+"ww2gun.c");
    wear("/d/Planar/Abyss/Nazi/obj/mask.c", "gas mask");

    set_level(16);
}


/* End of File */
