#include "macrosoft.h"

inherit FLOOR_3("stdhall.c");

void create() {
    ::create();
    set("exits", ([
      "east" : FLOOR_3("hall2.c"),
      "north" : FLOOR_3("office1n.c"),
      "west" : FLOOR_3("office1w.c"),
    ]) );
}

/* EOF */
