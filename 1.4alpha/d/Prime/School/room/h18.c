// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndText
You are at a three-way intersection in a typical high school hallway. The
hall goes to the east, towards the art departments, and to the northwest
and southwest.
EndText
    );
    set("exits", ([
    "northwest" :  S_ROOM("h16.c"),
    "southwest" : S_ROOM("h17.c"),
    "east" : S_ROOM("h19.c")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         