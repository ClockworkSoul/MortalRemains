#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_5("d3.c"),
    "south" : FLOOR_5("e4.c"),
    ]) );
    reset();
}

/* EOF */
