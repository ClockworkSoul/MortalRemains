#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_4("a5.c"),
    "south" : FLOOR_4("c5.c"),
    ]) );
}

/* EOF */
