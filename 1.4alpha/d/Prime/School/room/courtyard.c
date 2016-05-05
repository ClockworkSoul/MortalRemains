// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "High School Courtyard");
    set("long", @EndLong
You are in a small concrete courtyard in from of the main entrance to
Brainwash Senior High School, in the center of which stands a tall flagpole.
You can enter the school through the doors to the north, or return to the 
parking lot to the south.
EndLong
    );
    set("objects", ([
    ]) );
    set("exits", ([
    "south" : S_ROOM("parklote.c"),
    "north" : S_ROOM("entrance.c"),
    ]) );
    set("item_desc", ([
    "flagpole" : "Oddly, there is no flag flying on it.\n",
    "entrance" : "It's to the north.\n",
    "doors" : "They are made of thick, shatter-proof glass.\n",
    "lot" : "It's to the south.\n",
    "parking lot" : "It's to the south.\n",
    ]) );
}

/* EOF */
