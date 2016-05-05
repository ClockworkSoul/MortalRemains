
#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A hallway");
    set("long", "@@query_long");
    set("exits", ([
      "west" : FLOOR_7("n_hall1.c"),
      "east" : FLOOR_7("n_hall3.c"),
    ]) );
    set("item_desc", ([
    ]) );
}



string query_long() {
    string desc;

    desc = "You are in a long and featureless hallway "+
    "running east and west.";

    if (find_object_or_load(MS_D)->query_power())
	desc += " The hallway to the west seems to be blocked "+
	"by some kind of energy field.";

    return wrap(desc);
}

/* EOF */
