#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("b4.c"),
    "east" : FLOOR_5("c5.c"),
    "south" : FLOOR_5("b6.c"),
    "west" : FLOOR_5("a5.c"),
    ]) );
    reset();
}

/* EOF */
