
#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A T-Intersection");
    set("long", wrap("You are in the westernmost portion of a long "+
	"hallway. This particular portion of the hall seems to be "+
	"studded with force field nodules."));
    set("exits", ([
      "west" : FLOOR_7("tjunction.c"),
      "east" : FLOOR_7("n_hall2.c"),
    ]) );
    set("item_desc", ([
    ]) );
}


int receive_object(object ob) {
    if (find_object_or_load(MS_D)->query_power())
    {
	tell_object(ob, wrap("The way seems to be blocked "+
	    "by some kind of force field."));
	return 0;
    } else {
	return 1;
    }
}

/* EOF */
