// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
      "north" : FLOOR_2("cube07n.c"),
      "south" : FLOOR_2("cube07s.c"),
      "west" : FLOOR_2("floor6.c"),
      "east" : FLOOR_2("floor8.c"),
    ]) );
}

/* EOF */
