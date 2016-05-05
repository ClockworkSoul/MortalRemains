// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("author", "cyanide");
    set("short", "A Rocky Climb");
    set("long", @EndText
This is a steep rocky climb that appears as though it had been carved from
the rock by hundreds of years' worth of erosion. Above you lies a forest,
with what looks like the start of a path.
EndText
    );
    set("exits", ([
      "down" : AREA1("a1path04.c"),
      "up" : AREA1("a1forest01.c"),
    ]) );
    set("smell", ([
      "default" : "The organic smell of wet dirt wafts down "+
      "from above.\n",
    ]) );
}

/* EOF */
