// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
      "west" : FLOOR_2("floor9.c"),
      "north" : FLOOR_2("floor5.c"),
      "south" : FLOOR_2("floor15.c"),
      "east" : FLOOR_2("bossroom.c"),
    ]) );
}

/* EOF */
