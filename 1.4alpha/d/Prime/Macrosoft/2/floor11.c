// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    add("long", "Through a door to the south is the copy room.\n");
    set("exits", ([ 
      "north" : FLOOR_2("floor6.c"),
      "east" : FLOOR_2("floor12.c"),
      //    "south" : FLOOR_2("copyroom.c"),
    ]) );
}

/* EOF */
