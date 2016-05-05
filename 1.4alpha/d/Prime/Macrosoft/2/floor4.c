// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
      "north" : FLOOR_2("cube04n.c"),
      "south" : FLOOR_2("cube04s.c"),
      "west" : FLOOR_2("floor3.c"),
      "east" : FLOOR_2("floor5.c"),
    ]) );
}

/* EOF */
