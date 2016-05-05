#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
    "north" : FLOOR_5("c4.c"),
    "south" : FLOOR_5("c6.c"),
    "east" : FLOOR_5("d5.c"),
    "west" : FLOOR_5("b5.c"),
    ]) );
    reset();
}

/* EOF */
