// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "Teachers' Parking Lot");
    set("long", @EndLong
You are in the teacher' parking lot. There are many
cars here, but none seem to be worth real notice. 
The lot continues to the east.
EndLong
    );
    set("objects", ([
    ]) );
    set("exits", ([
      "east" : S_ROOM("parklotwest.c"),
    ]) );
    set("item_desc", ([
      "cars" : "They aren't much better than the student's cars.\n",
    ]) );
}

/* EOF */
