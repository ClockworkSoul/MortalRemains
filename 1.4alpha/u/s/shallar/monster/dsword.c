/*
** File: dsword.c
** Date: June 2000
** created by Shallar
** Done in honor of old Retsam. Thanks for being the best guildmaster
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
set("prevent _summon","1");
set ("author","shallar");
set("short","dancing sword");
    set ("long", @EndText
This is a magical dancing sword. It was summoned by Helion the
Sinner, but it got away. Be careful, it looks sharp!
EndText
   );
set("id",({"sword","dancing sword"}));
set_size(5);
set_name("dancing sword");
    set("gender", "neuter");
set("race","weapon");
set("undead",0);
set("alt_corpse","/u/s/shallar/weapon/hsword.c");
set("damage",({4,12}));
set("base_ac",1);
resistance("electricity", 0);
set("weapon_name","slash");
set("damage_type","slashing");
set_verbs(({"attack","slice"}));
set("stat/strength",15);
set("stat/constitution",24);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level(15);

}

void die(){
say (
"The sword clatters to the ground as you finish it off. It no \n" +
"longer has the ability to fight on its own, but it still glows \n" +
"with a magical arua. \n");

::die();
return 1;
}
