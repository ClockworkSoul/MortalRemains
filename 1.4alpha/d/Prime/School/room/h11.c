// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndLong
You are in a typical high school hallway. To the south is an exit from the
building, and the Nurse's Office is to the east. To the west is a 
stairwell leading up.
EndLong
    );
    set("objects", ([
    ]) );
    set("exits", ([
      "south" : S_ROOM("parklotwest.c"),
      "northwest" : S_ROOM("h12.c"),
      "east" : S_ROOM("nurse.c"),
    ]) );
    set("item_desc", ([
      "office" : "It's to the east.\n",
      "stairwell" : "You can use the stairs to go up.\n",

    ]) );
}

/* EOF */
