#include "macrosoft.h"

inherit FLOOR_3("stdhall.c");

void create() {
    ::create();
    set("exits", ([
        "west" : FLOOR_3("hall6.c"),
        "south" : FLOOR_3("office7s.c"),
        "east" : FLOOR_3("hall8.c"),
    ]) );
}

/* EOF */
