#include <mudlib.h>

inherit MONSTER;



void create ()
{
    ::create();
    set("author", "shya");
    seteuid(getuid());
    set("short", "a snowman");
    set("long", @Foo
A typical snowman with a carrot nose and all. 
Coal black eyes stare into your soul.
Foo
    );
    set("id", ({"snowman"}) );
    set_size(14);
    set_name("snowman");
    set("gender", "male");
    set("race", "snowman");
    set("damage", ({ 4,8 }) );
    set("weapon_name", "icepick");
    set_verbs( ({"attacks", "swings at"}) );
    enable_commands();
    set("natt", 1);
    set("chat_chance", 10);
    set("chat_output", ({
      "The snowman glares at you with his cold eyes.\n"
    }) );
    set("att_chat_output", ({
      "Go back to your warm bed girly man.\n"
    }) );
    set_level(7);
    arm("/d/Arctic/Shya/weapons/icepick.c", "icepick");
}



void init()
{
    command("wield icepick");
}
