#include "macrosoft.h"

inherit FLOOR_3("stdhall.c");

void create() {
    ::create();
    set("exits", ([
        "west" : FLOOR_3("hall3.c"),
        "north" : FLOOR_3("office4n.c"),
        "east" : FLOOR_3("office4e.c"),
    ]) );
}

/* EOF */
