/*
	File: penguin.c
	Desc: Aww...a cute little penguin.
	Date: 6-24-99
	Comments: wow spelled backwards is..wow.
*/
#include <mudlib.h>
object pelt;
inherit MONSTER;

void create() {
    ::create();
    set("author","sebastian");
    set_name("penguin");
    set("id", ({"penguin","bird"}));
    set("short", "a penguin");
    set("long", @EndText
A small, flightless waterfowl, straight out of Bloom County and
Outland.  Short, squat and totally covered in a permanent tuxedo.
EndText
    );
    set("race","bird");
    set("gender","neuter");
	set("lore_type", "Animal");
    set("damage", ({1,4}));
    set("weapon_name","beak");
    set("chat_chance", 4);
	set("chat_output", ({"The penguin wishes for wings that work.\n"}));
	set("att_chat_output", ({"The penguin, um, screams I guess.\n"}));
    set_size(2);
    set_verbs(({"nibble at","poke at","peck at"}));
    set_verbs2(({"nibbles at","pokes at","pecks at"}));
	// set("natt",1);
    set("stat/strength", 9);
    enable_commands();
    pelt = clone_object("/u/s/sebastian/items/ppelt.c");
    pelt->move(this_object());
    set_level(1);
}
