// Cyanide coded this.

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "");
    set("long", wrap(
      ) );
    set("exits", ([ 
      "west" : FLOOR_2("copyroom.c"),
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
