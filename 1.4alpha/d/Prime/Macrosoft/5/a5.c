#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("a4.c"),
    "east" : FLOOR_5("b5.c"),
    ]) );
    reset();
}

/* EOF */
