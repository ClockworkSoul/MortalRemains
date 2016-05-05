// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndText
You are in a typical high school hallway. To the east is one of the many 
exits to the building, and to the south is a stairwell leading up.
EndText
    );
    set("exits", ([
      "west" : S_ROOM("h19.c"),
    ]) );
    set("item_desc", ([
      "floor" : "Is carpeted in a kind of easy-to-clean muted blue. Weird.\n",
      "ceiling" : "A tiled suspension ceiling.\n",
    ]) );
}

/* EOF */
