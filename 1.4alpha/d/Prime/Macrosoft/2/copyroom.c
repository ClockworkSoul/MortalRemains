// Cyanide coded this.

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "");
    set("long", wrap(
      ) );
    set("exits", ([ 
      "east" : FLOOR_2("breakroom.c"),
      "north" : FLOOR_2("floor11.c"),
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
