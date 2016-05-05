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
The path here runs dangerously close to the edge of a crumbling cliff 
ledge, hundreds of feet above the ocean.
EndText
    );
    set("author", "cyanide");
    set("short", "On a Cliff Edge");
    set("exits", ([
      "northeast" : AREA1("a1path03.c"),
      "south" : AREA1("a1path02.c"),
    ]) );
    set("item_desc", ([
      "ocean" : "Its is hundreds of feet below you, and"+
      "churning violently.\n",
      "cliff" : "It is ancient and weathered.\n"+
      "There seems to be another ledge, far below you.\n",
      "ledge" : "It's just a ledge, it would seem.\n",
      "path" : "It continues to the south and northeast\n",
    ]) );
}

void init() {
    add_action("jump", "jump");
    add_action("climb", "climb");
}

int climb (string str) {
    if ((!str) ||
      (str!="down" && str!="to ledge")) {
	write("Climb where?\n");
	return 1;
    }

    str = TPN+" scrambles down the cliff face.\n";
    write("You scramble down the ledge.\n");
    TP->move_player(AREA1("a1ledge01.c"), str);

    return 1;
}

int jump() {
    write("Are you fucking insane?!?\n");
    return 1;
}









/* EOF */
