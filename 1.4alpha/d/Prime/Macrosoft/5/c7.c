#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("c6.c"),
    ]) );
    reset();
}

/* EOF */
