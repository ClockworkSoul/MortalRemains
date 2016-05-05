#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_4("a1.c"),
    "south" : FLOOR_4("c1.c"),
    ]) );
}

/* EOF */
