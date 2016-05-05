/*
** File: max.c
** Date: June 2000
** created by Shallar
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
set("prevent _summon","1");
set ("author","shallar");
set ("short","a green dog");
    set ("long", @EndText
Max is the long suffering companion of Marvin the Martian.
Max hopes Marvin can accomplish his goal of destroying the Earth,
so they can return home to Mars.
EndText
   );
set("id",({"max","dog"}));
set_size(2);
set_name("Max");
set ("race", "animal");
set("gender","male");
set("undead",0);
set("damage",({1,5}));
set("base_ac",6);
set("weapon_name","bite");
set_verbs(({"attack", "bite at", "knaw on"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level(4);

wear("u/s/shallar/armor/helm1.c","helm");
}
