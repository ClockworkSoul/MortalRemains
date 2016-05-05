// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    add("long", "To the west are the elevators.\n");
    set("exits", ([ 
      "north" : FLOOR_2("floor1.c"),
      "south" : FLOOR_2("floor11.c"),
      "west" : FLOOR_2("elevators.c"),
      "east" : FLOOR_2("floor7.c"),
    ]) );
}

/* EOF */
