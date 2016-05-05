#include <mudlib.h>

inherit MONSTER ;

#include "../food.h"

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nightmask");
    set("prevent_summon", 1);
    set("short", "cheesecake villager");
    set ("long", @EndText
This is a skeleton; there is no flesh left on its body.
He looks back at you with hollow eyes.
EndText
    );
    set("id", ({ "cheesecake", "villager" }) );
    set_size(4);
    set_name("cheesecake");
    set("wealth", random(40));
    set("gender", "neuter");
    set("race", "dessert");
    set("damage", ({ 1,4 }) );
    set("weapon_name", "creamy fists");
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 1);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(random(3));
    arm(WEAP+"loly.c");
    wear(ARM+"candy.c");
}
