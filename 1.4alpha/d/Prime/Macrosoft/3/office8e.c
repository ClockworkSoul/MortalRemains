// The executive offices.

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "An office");
    set("long", wrap(
	"You are in one of the offices of a high-ranking Macrosoft "+
	"executive. Expensive and tasteful furnishings decorate "+
	"the room, but it still seems cold somehow cold."
      ) );
    set("exits", ([ 
      "west" : FLOOR_3("hall8.c"),
      "east" : FLOOR_3("office8e2.c"),
    ]) );

    set("objects", ([ "executive" : MS_MON("adminasst.c") ]) );
set("pre_exit_func", ([
  "east" : "shehere"
]) );
reset();
}

int shehere() {
    if (present("alyson", TO)) {
	write("Alyson blocks your way!\n");
	return 1;
    } else {
	return 0;
    }
}

/* EOF */
