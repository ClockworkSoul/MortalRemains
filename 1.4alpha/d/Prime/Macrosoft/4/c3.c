#include "macrosoft.h"

inherit FLOOR_4("stdroom.c");

void create() {
    ::create();
    set("objects", ([
      "clo" : MS_MON("4boss.c")
    ]) );
reset();
set("exits", ([
  "west" : FLOOR_4("c2.c"),
  "east" : FLOOR_4("c4.c"),
  "north" : FLOOR_4("b3.c"),
  "south" : FLOOR_4("d3.c"),
]) );
}

/* EOF */
