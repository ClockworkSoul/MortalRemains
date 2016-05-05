#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "south" : FLOOR_5("d3.c"),
    "west" : FLOOR_5("c2.c"),
    ]) );
    reset();
}

/* EOF */
