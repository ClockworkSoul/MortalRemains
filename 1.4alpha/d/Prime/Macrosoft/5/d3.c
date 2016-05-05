#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("d2.c"),
    "east" : FLOOR_5("e3.c"),
    "south" : FLOOR_5("d4.c"),
    "west" : FLOOR_5("c3.c"),
    ]) );
    reset();
}

/* EOF */
