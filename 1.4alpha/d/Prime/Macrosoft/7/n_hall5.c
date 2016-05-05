
#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A hallway");
    set("long", "You are in a long and featureless hallway "+
      "running east and west.\n");
    set("exits", ([
      "west" : FLOOR_7("n_hall4.c"),
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([ "objects" : MS_MON("7boss.c") ]) ); 
reset();
}

/* EOF */
