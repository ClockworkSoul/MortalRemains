// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Canyon Bottom");
    set("long", wrap("You are beneath the walls of the river canyon "+
        "which may be climbable here. The lesser part of the flow "+
        "to the falls flows by below. To the north is a narrow path."));
    set("exits", ([
        "up" : AREA1("a1forest24.c"),
        "north" : AREA1("a1forest26.c"),
    ]) );
    set("item_desc", ([
    ]) );
    set("search_desc", ([
    ]) );
}

/* EOF */
