// The executive offices

#include "/u/c/cyanide/debug.h"
#include "macrosoft.h"

inherit MS_STD_ROOM;

mapping e_map = ([ 
"n" : "south", 
"s" : "north",
"e" : "west",
"w" : "east",
]);

void create() {
    int num;
    string dir;

    ::create();
    set("short", "An office");
    set("long", wrap(
	"You are in one of the offices of a high-ranking Macrosoft "+
	"executive. Expensive and tasteful furnishings decorate "+
	"the room, but it still seems cold somehow cold."
      ) );

    // This dynamically sets the room links. It takes a couple
    // extra CPU cycles, but it only gets done once, when the
    // room is first loaded.

    dir = base_name(TO);
    if (sscanf(dir, FLOOR_3("office%d%s"), num, dir) == 2)
	set("exits", ([ e_map[dir] : FLOOR_3("hall"+num) ]) );

set("objects", ([ "executive" : MS_MON("executive.c") ]) );
reset();
}

/* EOF */
