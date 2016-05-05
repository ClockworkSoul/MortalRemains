// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
      "north" : FLOOR_2("cube03n.c"),
      "south" : FLOOR_2("cube03s.c"),
      "west" : FLOOR_2("floor2.c"),
      "east" : FLOOR_2("floor4.c"),
    ]) );
}

/* EOF */
