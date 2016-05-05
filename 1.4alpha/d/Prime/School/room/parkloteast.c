// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "Eastern end of the Parking Lot");
    set("long", @EndLong
You are at the eastern end of the student's parking lot. There are many
cars here, but none seem to be worth real notice. To the north is the main
entrance to the school, and to the south is the school track. The lot 
continues to the west.
EndLong
    );
    set("objects", ([
    ]) );
    set("exits", ([
    "west" : S_ROOM("parklotwest.c"),
    "east" : S_ROOM("secgate.c"),
    "north" : S_ROOM("courtyard.c"),
    "south" : S_ROOM("trackhousenear.c")
    ]) );
    set("item_desc", ([
    "cars" : "Everything from 15 year old pieces of shit to shiny new "+
        "sports\ncars that daddy obviously bought.\n",
    "lot" : "It's mostly full of cars.\n",
    "entrance" : "I'm not expert, but that may be how you get in.\n",
    "track" : "There seem to be some people down the running around.\n",
    ]) );
}

/* EOF */         