// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 27 June 1999
// This is where players come after they finish the death
// sequence.

inherit ROOM;

#include <teleport.h>
#include <config.h>
#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("no_teleport", NO_IN_OR_OUT);
    set("short", "A Recovery Room");
    set("long", wrap(
	"You find yourself in a small recovery room. It is "+
	"completely featureless, with the exception of the "+
	"door leading to the south." 
      ) );
    set("exits", ([
      "out" : M_ROOM+"hospital/ER.c",
    ]) );
    set("safe", 1);
    set("item_desc", ([
      "room" : "Barely worth describing.\n",
      "door" : "It seems to lead out of here.\n",
    ]) );
}

// EOF
