/*
** File: teeth.c
** Date: June 2000
** created by Shallar
*/

#include <mudlib.h>

inherit MONSTER ;
object tooth;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
set("prevent _summon","1");
enable_commands();
tooth= clone_object("/u/s/shallar/stuff/tooth.c");
tooth->move(this_object());

set ("author","shallar");
set("short","Dr. Teeth");
    set ("long", @EndText
Dr. Teeth is the leader of the Electric Mayhem. He is their lead
singer and keyboard player. Somehow he intercepted the call for 
help from Pepperland. I don't think he was what they expected.
EndText
   );
set("id",({"teeth","dr teeth","dr. teeth"}));
set_size(3);
set_name("dr teeth");
set("race","muppet");
set("gender","male");
set("undead",0);
set("base_ac",5);
set("damage",({2,6}));
set("weapon_name","fist");
set_verbs(({"attack","pop"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
"Dr Teeth sez: You see, they were looking for the band from Pepperland, \n" +
"but had to settle instead with the melodious sounds of the Electric Mayhem!\n",
    }) );
    set ("att_chat_output", ({
    }) );
set_level(7);

}
