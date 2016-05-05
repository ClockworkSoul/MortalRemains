#include "macrosoft.h"

inherit FLOOR_3("stdhall.c");

void create() {
    ::create();
    set("exits", ([
        "west" : FLOOR_3("hall2.c"),
        "north" : FLOOR_3("office3n.c"),
        "east" : FLOOR_3("hall4.c"),
    ]) );
}

/* EOF */
