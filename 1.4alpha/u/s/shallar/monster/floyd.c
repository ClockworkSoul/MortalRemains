/*
**file: floyd.c
** Date: June 2000
** created by Shallar
*/

#include <mudlib.h>

inherit MONSTER ;
object guitar;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
set("prevent _summon","1");
enable_commands();
guitar= clone_object("/u/s/shallar/stuff/guitar.c");
guitar->move(this_object());

set ("author","shallar");
set("short","Floyd");
    set ("long", @EndText
Floyd is the lead guitar for the Electric Mayhem. He is a professional
musician who only works with the best. He also takes care of the 
drummer, Animal.
EndText
   );
set("id",({"floyd","musician"}));
set_size(3);
set_name("floyd");
set("race","muppet");
set("gender","male");
set("undead",0);
set("wealth",90);
set("base_ac",4);
set("damage",({2,6}));
set("weapon_name","guitar");
set_verbs(({"attack","whap"}));
set("chat_chance",18);
    set ("chat_output", ({
"Floyd sez: Let's take care of the Blue Meanies with our own version \n"+
"of the blues.\n",
    }) );
    set ("att_chat_output", ({
    }) );
set_level(6);

}
