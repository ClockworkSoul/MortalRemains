// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndLong
You are at a three-way intersection in a typical high school hallway. The
hall goes to the south, towards the gym, and to the northeast and
southeast.
EndLong
    );
    set("objects", ([
    ]) );
    set("exits", ([
    "southeast" : S_ROOM("h14.c"),
    "northeast" : S_ROOM("h15.c"),
    "south" : S_ROOM("h12.c"),
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */