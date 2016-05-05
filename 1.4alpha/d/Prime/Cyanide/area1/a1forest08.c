// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Forest");
    set("long", wrap("You are in a particularly thickly wooded "+
	"region of the forest, bordered on the south by an "+
	"overgrown thicket. A large stump sits here blocking "+
	"further travel east, but the path continues around it "+
	"to the southeast. To the south, a narrow game path leads "+
	"into the thicket. The path also heads west, around a bend."));
    set("exits", ([
      "west" : AREA1("a1forest05.c"),
      "southeast" : AREA1("a1forest14.c"),
      "south" : AREA1("a1thicket.c"),
    ]) );
    set("item_desc", ([
      "stump" : wrap("It seems old and rotted. Probably the effects"+
	" of a storm a few years ago. Strangely, you cannot seem "+
	"to find the tree it used to belong to."),
    ]) );
    set("search_desc", ([
      "stump" : wrap("It seems to have a hollow spot in it. You "+
	"may be able to enter it..."),
    ]) );
}

void init() {
    add_action("enter", "enter");
}

int enter(string str) {
    if (!str) {
	write("Enter what?\n");
	return 1;
    }

    if (str=="stump" || str=="hollow") {
	write("You wriggle into the stump...\n");
	say(TPN+" squeezes into the hollow in the stump!\n");
	TP->move_player("/d/Prime/Toril/Arabel/rooms/rm302.c", "SNEAK");
	say(TPN+" climbs out of the underbrush.\n");
	write("You find yourself in another part of the forest.\n");
	return 1;
    }

    return 0;
}


/* EOF */
