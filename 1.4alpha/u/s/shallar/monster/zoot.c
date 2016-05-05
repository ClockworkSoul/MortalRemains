/*
** file: zoot.c
** Date: June 2000
** created by Shallar
*/

#include <mudlib.h>

inherit MONSTER ;
object saxaphone;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
set("prevent _summon","1");
enable_commands();
saxaphone= clone_object("/u/s/shallar/stuff/sax.c");
saxaphone->move(this_object());

set ("author","shallar");
set("short","Zoot");
    set ("long", @EndText
Zoot is the sax player for the Electric Mayhem. He is one cool cat.
EndText
   );
set("id",({"zoot","musician"}));
set_size(3);
set_name("zoot");
set("race","muppet");
set("gender","male");
set("undead",0);
set("wealth",90);
set("base_ac",6);
set("damage",({2,6}));
set("weapon_name","saxaphone");
set_verbs(({"attack","pop"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
"Zoot blasts on the sax and stops. He looks a bit lost, but he was in the zone. \n",
    }) );
    set ("att_chat_output", ({
    }) );
set_level(6);

}
