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
    "west" : S_ROOM("h17.c")
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */         