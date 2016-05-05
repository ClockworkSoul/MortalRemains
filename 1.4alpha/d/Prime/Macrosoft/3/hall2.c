#include "macrosoft.h"

inherit FLOOR_3("stdhall.c");

void create() {
    ::create();
    set("exits", ([
        "west" : FLOOR_3("hall1.c"),
        "north" : FLOOR_3("office2n.c"),
        "east" : FLOOR_3("hall3.c"),
        "south" : FLOOR_3("elevators.c"),
    ]) );
}

/* EOF */
