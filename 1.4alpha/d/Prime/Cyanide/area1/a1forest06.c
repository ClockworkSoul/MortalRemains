// The forest in Cyanide's area.
// This room needs unlocking and grate opening functions.
// Will probably lead to a room in the maze.

#include <mudlib.h>
#include "cy.h"

int disturbed = 0, locked = 1, open = 0;

inherit ROOM;

void create() {
    object ob;

    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Clearing");
    set("long", "@@query_long");
    set("exits", ([
      "east" : AREA1("a1forest11.c"),
      "southwest" : AREA1("a1forest03.c"),
    ]) );
    set("item_desc", ([
      "pile" : "@@query_pile",
      "leaves" : "@@query_pile",
    ]) );
}

void init() {
    add_action("disturb", "take");
    add_action("disturb", "move");
    add_action("disturb", "get");
}

string query_pile() {
    string str;

    if (!disturbed)
	str = "Just a simple pile of leaves.\n";
    else
	str = "";

    return str;
}

int disturb(string str) { 
    object ob;

    if ((str=="pile" || str=="leaves") && !disturbed) {
	disturbed = 1;
	add("item_desc", ([ "grating" : "@@query_grating" ]) );
	ob = clone_object(OBJ+"/leaves.c");
	ob->move(TO);
    }

    return 0;
}

string query_grating() {
    string str;

    if (disturbed) {
	if (!open) {
	    str = "The grating is locked.\n";
	} else {
	    str = "The grating is open.\n";
	}
    } else {
	str = "You don't see that here.\n";
    }

    return str;
}

string query_long() {
    string str = "You are in a clearing, with a forest surrounding "+
    "you on all sides. A path leads east, and another leads "+
    "southwest.";

    if (disturbed)
	str += "\nThere is a grating securely fastened into the ground.";
    else
	str += "\nThere is a large pile of leaves here.";

    return wrap(str);
}

/* EOF */
