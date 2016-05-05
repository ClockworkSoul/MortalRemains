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
      "west" : FLOOR_3("office8e.c"),
    ]) );

    set("objects", ([ "dy-mar" : MS_MON("3boss.c") ]) );
reset();
}

/* EOF */
