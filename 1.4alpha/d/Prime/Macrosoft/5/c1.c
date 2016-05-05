#include "macrosoft.h"

inherit FLOOR_5("std5.c");

void create() {
    ::create();
    set("exits", ([
      "south" : FLOOR_5("c2.c"),
    ]) );
    set("objects", ([
      "boss" : MS_MON("5boss.c")
    ]) );
reset();
}

/* EOF */
