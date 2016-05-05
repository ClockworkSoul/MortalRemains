#include "macrosoft.h"

inherit FLOOR_3("stdhall.c");

void create() {
    ::create();
    set("exits", ([
      "west" : FLOOR_3("hall7.c"),
      "south" : FLOOR_3("office8s.c"),
      "east" : FLOOR_3("office8e.c"),
    ]) );
}

/* EOF */
