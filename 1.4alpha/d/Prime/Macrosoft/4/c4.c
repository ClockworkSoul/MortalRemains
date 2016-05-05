#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_4("c3.c"),
    "east" : FLOOR_4("c5.c"),
    ]) );
}

/* EOF */
