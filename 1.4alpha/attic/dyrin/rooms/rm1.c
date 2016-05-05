// File: std.c
// Purpose: Well, cloning for other rooms. :)
// Date: Like June, 1999
// Other Notes: *Shrug* There is none, yet :)
// Credits: This room belonged to Cy.  Borrowed for copying (x.c)

#include <config.h>
#include <mudlib.h>
#include "area.h"

inherit ROOM;


void create() {
    ::create();
    set("author", "dyrin");
    set("light", 1);
    set("short", "A Street");
    set("long",@EndText
This is the end of the road.  There are buildings and cars
that have been blown up, and a mix of blood and slime along
the street.  This was once a beautiful neighborhood. Time
seems to have taken a toll on it.
EndText
);
    set("exits", ([
   "east" : ROOMS+"rm2.c",
    ]) );
    set("item_desc", ([
    "pool" : "It's a pool, duh."
    ]) );
}

// EOF
