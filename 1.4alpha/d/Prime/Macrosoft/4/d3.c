#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_4("c3.c"),
    "south" : FLOOR_4("e3.c"),
    ]) );
}

/* EOF */
