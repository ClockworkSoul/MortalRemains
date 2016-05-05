/*
** File: /u/r/raven/entrance.c
** Author: Raven
** 
** Entrance to area
*/

#include <config.h>
#include <mudlib.h>

void init() {
    ::init();
    add_action("climb_tree", "climb");  
}

int climb_tree(string str) {
    if (!str || str!="tree") {
	write("climb what?\n");
	return 1;
    }
say(TPN+ " tries to jump to a low branch but is entirely unsuccessful\n");
write(wrap(
"You jump for the lowest branch but grab nothing but air.\n"));
    return 1;
}

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "raven");
    set( "short", "Forest Entrance" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
You are standing on the edge of a great forest.  To the north is a path
leading into the forest.  In the distance to the East you see what appears
to be a town.  And to the South is a path across a field.
EndText
    );
    set( "exits", ([
      "north" : "/u/r/raven/workroom.c",
      "south" : "/u/r/raven/workroom.c"
    ]) );
    set( "item_desc", ([
      "forest" : "A great many trees.  Many appear to be very old.\n",
      "trees" : "Trees that appear to be as old as the world itself.\n",
      "path" : "A path leading into the dense trees.\n",
      "field" : "A field of wild grass.\n",
      "grass" : "It is grass, what did you expect?.\n",
      "town" : "You cannot see the town from here.\n",
	"city" : "You cannot see the town from here.\n",
]) );
}


