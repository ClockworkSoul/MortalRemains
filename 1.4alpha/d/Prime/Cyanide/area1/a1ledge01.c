/*
** Creator: Cyanide (28 Jan 98)
*/

#include <mudlib.h>
#include "../cy.h"

inherit ROOM;

void create() {
    ::create();
    set("light", 1);
    set("long", @EndText
You are standing on a narrow ledge on a weathed cliff perched about a
hundred feet above a restless ocean. You see no reason why you should
remain here.
EndText
    );
    set("short", "Standing on a Ledge");
    set("exits", ([
    ]) );
    set("item_desc", ([
      "ocean" : "It is far below you, and "+
      "churning violently.\n",
      "cliff" : "It is ancient and weathered.\n"+
      "There seems to be another ledge, far below you.\n",
      "ledge" : "It's very narrow...\n",
    ]) );
}

void init() {
    add_action("jump", "jump");
    add_action("climb", "climb");
}

int climb (string str) {
    if ((!str) ||
      (str!="up" && str!="to ledge" && str!="down")) {
	write("Climb where?\n");
	return 1;
    }

    if (str=="up") {
	str = TPN+" climbs up the cliff face.\n";
	write("You climb up the ledge.\n");
	TP->move_player(AREA1("a1view01.c"), str);
    } else {

	str = TPN + " scrambles down the cliff face.\n";
	write("You climb further down the cliff face.\n");
	TP->move_player(AREA1("a1ledge02.c"), str);
    }

    return 1;
}

int jump() {
    write("Are you fucking insane?!?\nI'm gonna log this for Cyanide. "+
      "He'll have a good laugh.\n");
    return 1;
}


/* EOF */
