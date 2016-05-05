// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndText
You are in a typical high school hallway. There are classrooms to the east
and west. There is a stariwell to the east leading up, and a door to the
north that leads outside.
EndText
    );
    set("exits", ([
    "west"  : S_ROOM("stairwell3.c"),
    "south" : S_ROOM("h111.c"),
    "north" : S_ROOM("/* OUTSIDE - NORTH FIELDS*/")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         