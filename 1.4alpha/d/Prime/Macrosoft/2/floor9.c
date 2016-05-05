// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
      "south" : FLOOR_2("cube09s.c"),
      "north" : FLOOR_2("cube09n.c"),
      "west" : FLOOR_2("floor8.c"),
      "east" : FLOOR_2("floor10.c"),
    ]) );
}

/* EOF */
