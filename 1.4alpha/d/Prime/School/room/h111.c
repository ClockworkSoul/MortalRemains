// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndText
You are in a typical high school hallway. There are classrooms to the east
and west.
EndText
    );
    set("exits", ([
    "south" : S_ROOM("h110.c"),
    "north" : S_ROOM("h112.c")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         