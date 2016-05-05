// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Forest");
    set("long", wrap("Here, the pines thin out quite a bit, "+
        "allowing the view of a great canyon whose edge lies a mere "+
        "10 paces to the east. To the south, the path seems to run "+
        "much closer to the canyon rim."));
    set("exits", ([
        "northwest" : AREA1("a1forest17.c"),
        "south" : AREA1("a1forest23.c"),
    ]) );
    set("item_desc", ([
        "canyon" : "You can't see it too well from here.\n",
        "rim" : "You can reach it by going south.\n",
        "edge" : "You can reach it by going south.\n",
    ]) );
    set("search_desc", ([
    ]) );
}

/* EOF */
