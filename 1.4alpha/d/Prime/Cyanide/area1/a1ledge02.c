/*
** Creator: Cyanide (28 Jan 98)
*/

#include <mudlib.h>
#include "../cy.h"

int i = 1;

inherit ROOM;

void create() {
    ::create();
    set("light", 1);
    set("long", @EndText
You are standing on a narrow ledge on a weathed cliff perched about a
hundred feet above a restless ocean. There is a small dark cave 
entrance directly to the east.
EndText
    );
    set("short", "Standing on a Ledge");
    set("exits", ([
      "east" : MAIN+"/crack.c",
    ]) );
    set("item_desc", ([
      "ocean" : "It is far below you, and "+
      "churning violently.\n",
      "cliff face" : "There seems to be a small hole in the cliff face here.\n",
      "hole" : "There seems to be something in it...\n",
      "cliff" : "There seems to be a small hole in the cliff face here.\n",
      "ledge" : "It's very narrow...\n",
      "cave" : "Very dark indeed...\n",
    ]) );
    set("exit_msg", ([
      "east" : "$N squeezes into the crack in the cliff face.",
    ]) );
    set("pre_exit_func", "dark");
}

void init() {
    add_action("jump", "jump");
    add_action("search", "search");
    add_action("climb", "climb");
}

int climb (string str) {
    if ((!str) ||
      (str!="up" && str!="to ledge")) {
	write("Climb where?\n");
	return 1;
    }

    str = TPN+" climbs up the cliff face.\n";
    write("You climb up the ledge.\n");
    TP->move_player(AREA1("a1ledge01.c"), str);

    return 1;
}

int jump() {
    write("Are you insane?!?\n");
    return 1;
}

int search( string str ) {
    object torch;

    seteuid(getuid());

    if (str=="hole") {
	if (i) {
	    write("You find a torch in the hole, and take it.\n");
	    say(wrap(TPN+" reaches into a hole in the cliff face and "+ 
		"pulls out a torch."));
	    torch = clone_object("/obj/obj/torch.c");
	    torch->move(TP);
	    i = 0;
	} else {
	    write("It is empty.\n");
	}
	return 1;
    }
    return 0;
}

void dark() {
    write("You crawl into the darkness...\n");
    return;
}

/* EOF */
