#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("b3.c"),
    "south" : FLOOR_5("b5.c"),
    ]) );
    reset();
}

/* EOF */
