// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Forest Path");
    set("long", wrap("You are at at fork in the forest path. The "+
    "path starts from the north, and splits here, heading southeast "+
    "and southwest."));
    set("exits", ([
        "north" : AREA1("a1forest01.c"),
        "southeast" : AREA1("a1forest05.c"),
        "southwest" : AREA1("a1forest07.c"),
    ]) );
    set("item_desc", ([
        "southeast path" : "The land in that direction seems to "+
            "be lower ground.\n",
        "southwest path" : "That path is a bit higher than the "+
            "other.\n",
        "path" : "Which one?\n",
    ]) );
    set("search_desc", ([
    ]) );
}

/* EOF */
