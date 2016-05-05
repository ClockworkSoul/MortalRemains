// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndText
You are in a typical high school hallway. The hall continues to the east,
toward an area called the "commons", and to the southwest. To the north is
a hallway of classrooms, and a stairwell leading up is to the west of here.
EndText
    );
    set("exits", ([
    "east" : S_ROOM("commons.c"),
    "southwest" : S_ROOM("h13.c"),
    "north" : S_ROOM("h110.c"),
    "west" : S_ROOM("stairwell2.c")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         