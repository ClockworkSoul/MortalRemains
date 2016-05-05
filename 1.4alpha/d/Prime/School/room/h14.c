// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndText
You are in a typical high school hallway. To the east is the main entrance
of the school. The school's main office is to the north, and the hall 
continues to the northwest.
EndText
    );
    set("exits", ([
    "northwest" :  S_ROOM("h13.c"),
    "north" : S_ROOM("mainoffice.c"),
    "east" : S_ROOM("entrance.c")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         