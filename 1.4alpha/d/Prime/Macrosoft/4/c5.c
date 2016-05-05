#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_4("c4.c"),
    "north" : FLOOR_4("b5.c"),
    "south" : FLOOR_4("d5.c"),
    ]) );
}

/* EOF */
