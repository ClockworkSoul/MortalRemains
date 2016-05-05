#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "east" : FLOOR_4("a3.c"),
    "west" : FLOOR_4("a1.c"),
    ]) );
}

/* EOF */
