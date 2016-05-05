#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "east" : FLOOR_5("b3.c"),
    "south" : FLOOR_5("a4.c"),
    ]) );
    reset();
}

/* EOF */
