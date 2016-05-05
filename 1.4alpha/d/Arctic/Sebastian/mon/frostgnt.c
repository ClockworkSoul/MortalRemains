/*
	File name: frostgnt.c
	Description: It's a Frost Giant, pretty obvious.
	Date: June 23 1 triple 9OD
	Comments:  My first monster, ain'tcha proud?
	Other Comments: Belly-Buttons smell funny.
*/

#include <mudlib.h>
inherit MONSTER;


void create(){
    ::create();
    seteuid(getuid());
	set("prevent_summon", 1);
    set("author","Sebastian");
	set("short", "a frost giant");
    set("long", @EndText
	A tall, massive behemoth stands before you, his large frame
	blotting out the sun.  From the scars across his body to the
	large axe in his hands, you realize, he's all business.
EndText
    );
    set("id", ({"frost giant", "giant"}));
	set_size(21);
    set_name("frost giant");
    set("gender","male");
    set("race","giant");
    set("damage", ({1,10}));
    set("weapon_name", "fists");
    set_verbs(({"swing at", "punch", "slam"}));
    set_verbs2(({"swings at","punches","slams"}));
    enable_commands();
    set("chat_chance",0);
	arm("/d/Arctic/Sebastian/weapon/greataxe.c", "great axe");
    set("stat/strength", 24);
    set("stat/constitution",18);
	set_level(15);
	set_skill("Axes", 1, "Strength");
	set("resist_type", (["cold":0]));
    wear("/u/s/sebastian/armor/icehelm.c","helm");
    wear("/u/s/sebastian/armor/furs.c" ,"furs");
}
