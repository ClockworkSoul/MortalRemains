// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
      "north" : FLOOR_2("cube02n"),
      "south" : FLOOR_2("cube02s"),
      "west" : FLOOR_2("floor1.c"),
      "east" : FLOOR_2("floor3.c"),
    ]) );
}

/* EOF */
