// The collective

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "Blast Plated Hallway");
    set("long", @EndText
You have entered a series of hallways, all of which are covered with some
kind of thick blast plating. What is most unusual about this floor is that
none of the hallways seem to lead to any offices of any kind. This looks
more like some kind of bizarre arena than anything else.
EndText
    );
    set("item_desc", ([
    ]) );
    set("objects", ([
      "warrior" : MS_MON("gunner.c"),
    ]) );
}

/* EOF */
