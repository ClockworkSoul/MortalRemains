#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "east" : FLOOR_4("a2.c"),
    "south" : FLOOR_4("b1.c"),
    ]) );
}

/* EOF */
