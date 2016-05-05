// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "Western end of the Parking Lot");
    set("long", @EndLong
You are at the eastern end of the student's parking lot. There are many
cars here, but none seem to be worth real notice. To the north is a smaller
entrance to the school. The lot continues to the east, and to the west is
the teachers' parking lot.
EndLong
    );
    set("objects", ([
    ]) );
    set("exits", ([
    "west" : S_ROOM("parklott.c"),
    "east" : S_ROOM("parklote.c"),
    "north" : S_ROOM("h11.c"),
    ]) );
    set("item_desc", ([
    "cars" : "Everything from 15 year old pieces of shit to shiny new "+
        "sports\ncars that daddy obviously bought.\n",
    "lot" : "It's mostly full of cars.\n",
    "entrance" : "I'm not expert, but that may be how you get in.\n",
    ]) );
}

/* EOF */         