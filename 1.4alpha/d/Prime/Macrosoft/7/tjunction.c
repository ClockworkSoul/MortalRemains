
#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A T-Intersection");
    set("long", "@@query_long");
    set("exits", ([
      "west" : FLOOR_7("torture.c"),
      "east" : FLOOR_7("n_hall1.c"),
    ]) );
    set("item_desc", ([
    ]) );
}

string query_long() {
    string desc;

    desc = "You have reached the end of a long hallway, where it "+
        "intersects another long, twisting hallway that runs to "+
        "the west and east.";

    if (find_object_or_load(MS_D)->query_power())
        desc += " The hallway to the east seems to be blocked "+
            "by some kind of energy field.";
    
    return wrap(desc);
}

/* EOF */
