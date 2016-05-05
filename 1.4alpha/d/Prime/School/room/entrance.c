// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "High School Main Entrance");
    set("long", @EndLong
You are just inside the main entrance to Brainwash Senior High School.
Hallways lead to the east and west, and a set of glass doors leads outside
to the parking lot.
EndLong
    );
    set("objects", ([
    ]) );
    set("exits", ([
      "south" : S_ROOM("parkloteast.c"),
      "west" : S_ROOM("h14.c"),
      "east" : S_ROOM("h17.c"),
    ]) );
    set("item_desc", ([
      "hallways" : "They lead east and west.\n",
      "doors" : "They lead outside to the parking lots.\n",
    ]) );
}

/* EOF */
