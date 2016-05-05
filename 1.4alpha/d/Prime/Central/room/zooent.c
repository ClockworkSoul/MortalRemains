// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "Entrance to the "+CITY_NAME+" Zoo");
    set("long", wrap(
	"You are standing at the main entrance to the "+CITY_NAME+
	" Zoo. To the south, a large sign states in big bubble "+
	"letters 'PETTING ZOO!'. Other paths lead to the "+
	"north and west, but appear to be blocked off."    
      ) );
    set("exits", ([
      "east" : M_ROOM+"road0_-2.c",
      "south" : "/d/Prime/Petzoo/rooms/zoo7.c",
    ]) );
    set("item_desc", ([
    ]) );
}

// EOF

