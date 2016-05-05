#include "macrosoft.h"

inherit FLOOR_3("stdhall.c");

void create() {
    ::create();
    set("exits", ([
        "west" : FLOOR_3("hall5.c"),
        "south" : FLOOR_3("office6s.c"),
        "east" : FLOOR_3("hall7.c"),
        "north" : FLOOR_3("elevators.c"),
    ]) );
}

/* EOF */
