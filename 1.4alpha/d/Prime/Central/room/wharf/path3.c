inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "Top of a Cliff");
    set("long", @EndText
You are standing on a thickly overgrown path at the top of a cliff. A 
rusty ladder leads down to the cliff base, completely obscured by fog,
and you can somewhat make out a path leading generally to the northwest.
EndText
    );
    set("exits", ([
      "down" : M_ROOM+"wharf/path2.c",
      "northwest" : M_ROOM+"wharf/path4.c",
    ]) );
    set("item_desc", ([
      "fog" : "You seem to have climbed above it.\n",
      "overgrowth" : "It is quite lush back here.\n",
      "ladder" : "It is old and rusty, but should hold your weight.\n"
    ]) );
    set("exit_msg", ([
      "down" : "$N carefully climbs down the old, rusty ladder.\n"
    ]) );
    set("smell", ([
      "default" : wrap("The amell of salty sea air is strong here."),
    ]) );
}

/* EOF */
