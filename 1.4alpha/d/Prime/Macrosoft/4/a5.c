#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("exits", ([
    "west" : FLOOR_4("a4.c"),
    "south" : FLOOR_4("b5.c"),
    ]) );
}

/* EOF */
