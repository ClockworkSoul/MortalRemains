#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("c1.c"),
    "south" : FLOOR_5("c3.c"),
    "east" : FLOOR_5("d2.c"),
    "west" : FLOOR_5("b2.c"),
    ]) );
    reset();
}

/* EOF */
