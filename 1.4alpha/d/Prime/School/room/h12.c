// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "A Hallway");
    set("long", @EndLong
You are in the athletic portion of the school. To the west is the gym, and
to the east is the entrance to the athletic locker rooms. Set into the 
wall is a large glass case full of trophies various students have won over
the years.
EndLong
    );
    set("objects", ([
    ]) );
    set("exits", ([
      "southeast" : S_ROOM("h11.c"),
      "east" : S_ROOM("lockent.c"),
      "west" : S_ROOM("gym.c"),
      "north" : S_ROOM("h13.c"),
    ]) );
    set("item_desc", ([
      "case" : "It contains many, many trophies.\n",
      "trophies" : "They are awards for victories won in football, "+
      "basketball, and track, mostly.\n",
    ]) );
}

/* EOF */
