#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("c3.c"),
    "south" : FLOOR_5("c5.c"),
    ]) );
    reset();
}

/* EOF */
