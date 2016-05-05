// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "Art Section");
    set("long", @EndText
You are in the art section of the school. The chorus room is to the north,
and art studios are to the south. There is a great deal of art on the 
wall here.
EndText
    );
    set("exits", ([
    "west" : S_ROOM("h18.c"),
    "east" : S_ROOM("h10.c")
    ]) );
    set("item_desc", ([
    "art" : "It's the students work. Crap, mostly.\n",
    ]) );
}

/* EOF */         