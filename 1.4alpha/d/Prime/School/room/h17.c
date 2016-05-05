// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndText
You are in a typical high school hallway. To the west is the main entrance
of the school, and to the east is the school library.
EndText
    );
    set("exits", ([
    "northeast" :  S_ROOM("h18.c"),
    "east" : S_ROOM("library.c"),
    "west" : S_ROOM("entrance.c")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         