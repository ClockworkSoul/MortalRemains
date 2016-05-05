/*
** File: marv.c
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
    set ("short", "Marvin the Martian");
    set ("long", @EndText
Here is a small martian which appears to be very agitated. His ship
has crashed into the yellow ship in front of you and he is now 
stuck here with no way to return to Mars.
EndText
    );
set("id",({"marvin","martian"}));
    set_size(4);
    set_name("Marvin");
    set("gender","male");
    set("race","martian");
set("base_ac",4);
set("ac",2);
    set("undead",0);
set("damage",({1,6}));
    set("weapon_name","ray");
    set_verbs(({"attack","shoot at","fire at","get a bead on"}));
set("ammo",(["E-clip":500]));
    set ("chat_chance", 10);
    set ("chat_output", ({
"Marvin curses his arch enemy, Duck Dodgers! \n",
"Marvin watches a rock fall on his head. His body collapses and all \n" +
"that is left is his helmet and two little feet running around making \n"+
"muffled noises. \n",
      "Marvin sets his Space Modulator to disintegrate and points it at you!\n",
      "Marvin says: Oh dear... I'm going to have to exterminate you.\n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(9);

    set("wealth",55);
    wear("/u/s/shallar/armor/helm1.c","helm");
    arm("u/s/shallar/weapon/mod.c","ray");
}
