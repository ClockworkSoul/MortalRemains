// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndText
You are in a typical high school hallway. The hall continues to the west,
toward an area called the "commons", and to the southeast.
EndText
    );
    set("exits", ([
    "west" : S_ROOM("commons.c"),
    "southeast" : S_ROOM("h18.c")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         