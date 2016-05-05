#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_4("c1.c"),
    "east" : FLOOR_4("c3.c"),
    ]) );
}

/* EOF */
