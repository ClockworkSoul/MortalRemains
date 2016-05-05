#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("b2.c"),
    "east" : FLOOR_5("c3.c"),
    "south" : FLOOR_5("b4.c"),
    "west" : FLOOR_5("a3.c"),
    ]) );
    reset();
}

/* EOF */
