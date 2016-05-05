#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("a3.c"),
    "west" : FLOOR_5("elevators.c"),
    "south" : FLOOR_5("a5.c"),
    ]) );
    reset();
}

/* EOF */
