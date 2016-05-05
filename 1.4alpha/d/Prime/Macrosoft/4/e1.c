#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "east" : FLOOR_4("e2.c"),
    "north" : FLOOR_4("d1.c"),
    ]) );
}

/* EOF */
