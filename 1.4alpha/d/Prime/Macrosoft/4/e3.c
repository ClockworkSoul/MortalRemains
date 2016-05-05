#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_4("e2.c"),
    "east" : FLOOR_4("e4.c"),
    "north" : FLOOR_4("d3.c"),
    ]) );
}

/* EOF */
