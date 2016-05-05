#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_5("d5.c"),
    "north" : FLOOR_5("e4.c"),
    ]) );
    reset();
}

/* EOF */
