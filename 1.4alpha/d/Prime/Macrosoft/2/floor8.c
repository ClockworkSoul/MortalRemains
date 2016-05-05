// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
      "north" : FLOOR_2("cube08n.c"),
      "south" : FLOOR_2("cube08s.c"),
      "west" : FLOOR_2("floor7.c"),
      "east" : FLOOR_2("floor9.c"),
    ]) );
}

/* EOF */
