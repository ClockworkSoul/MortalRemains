#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("c2.c"),
    "south" : FLOOR_5("c4.c"),
    "east" : FLOOR_5("d3.c"),
    "west" : FLOOR_5("b3.c"),
    ]) );
    reset();
}

/* EOF */
