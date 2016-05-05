#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("c5.c"),
    "south" : FLOOR_5("c7.c"),
    "east" : FLOOR_5("d6.c"),
    "west" : FLOOR_5("b6.c"),
    ]) );
    reset();
}

/* EOF */
