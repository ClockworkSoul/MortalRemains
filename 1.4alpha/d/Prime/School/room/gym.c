// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "");
    set("long", @EndText
EndText
    );
    set("exits", ([
    "west"  : S_ROOM("/*OUTSIDE*/"),
    "east" : S_ROOM("h12.c")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         