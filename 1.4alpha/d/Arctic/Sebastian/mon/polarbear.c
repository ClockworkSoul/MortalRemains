/*
	File: polarbear.c
	Desc: Pretty self explanitory.  okay, it's a blender.
	Date: June 23 1999
	Other Comments: Swiss cheese is holy.
*/
#include <mudlib.h>
object pelt;
inherit MONSTER;
void create(){
    ::create();
    seteuid(getuid());
    set("short", "a polar bear");
    set("long" , @Polar
It's one of those sleek looking mammals with pure white fur.  Although
timid, they are ferocious fighters.
Polar
    );
    set("id", ({"polar bear","bear","animal"}));
    set_size(8);
	set("stat/constitution", 18);
    set_name("polar bear");
    set("gender", "neuter");
    set("race","bear");
    set("damage", ({1,8}));
    set("weapon_name", "claws");
    set_verbs(({"swing at", "crush", "swipe at"}));
    set_verbs2(({"swings at","crushes","swipes at"}));
    enable_commands();
    set("natt",1);
    set("chat_chance",4);
    set("chat_output", ({"the polar bear sniffs the air.\n"}));
    set("att_chat_output", ({"the polar bear growls angrily.\n"}));
    pelt = clone_object("/u/s/sebastian/items/bpelt.c");
    pelt->move(this_object());
	set_level(9);
}
