// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Rocky Ledge");
    set("long", wrap("You are on a ledge about halfway up the wall "+
    "of the river canyon. You can see from here that the main flow "+
    "to the falls twists along a passage which is impossible for "+
    "you to enter. Below you is the canyon bottom. Above you is "+
    "more cliff, which appears climbable."));
    set("exits", ([
        "up" : AREA1("a1forest23.c"),
        "down" : AREA1("a1forest25.c"),
    ]) );
    set("item_desc", ([
    ]) );
    set("search_desc", ([
    ]) );
}

/* EOF */
