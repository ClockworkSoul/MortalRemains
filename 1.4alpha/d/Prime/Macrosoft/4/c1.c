#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_4("elevators.c"),
    "east" : FLOOR_4("c2.c"),
    "south" : FLOOR_4("d1.c"),
    "north" : FLOOR_4("b1.c"),
    ]) );
}

/* EOF */
