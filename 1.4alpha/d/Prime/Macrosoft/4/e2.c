#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_4("e1.c"),
    "east" : FLOOR_4("e3.c"),
    ]) );
}

/* EOF */
