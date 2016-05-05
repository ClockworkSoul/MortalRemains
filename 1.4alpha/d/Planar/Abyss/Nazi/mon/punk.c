/*
**File: punk.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "NSD");
    set("short", "gang punk");
    set ("long", @EndText
One of the five punks from the demonizer gang. 
He's wearing a hockey mask, and wielding a 
baseball bat.
EndText
    );
    set("id", ({ "gang punk", "punk"  }) );
    set_size(6);
    set_name("gang punk");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("lore_type", "monster lore");
    set("damage", ({9, 16}) );
    set("damage_type", "piercing");
    set("weapon_name", "fists");
    set_verbs( ({ "attack", "hit", "swing at", "peer at"}) ) ;
    set("nat", 1);
    set("chat_chance", 0);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(16);
    set("aggressive", 1);
    arm("/d/Prime/Central/weap/club.c");
    wear("?", "?");
}

/* End of File */
