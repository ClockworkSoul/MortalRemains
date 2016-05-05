// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Canyon View");
    set("long", wrap("You are at the top of a great canyon on its "+
    "west wall. From here there is a marvelous view of the canyon "+
    "and parts of the river upstream. Across the canyon, the walls "+
    "of the white cliffs join the mighty ramparts of great "+
    "mountains to the east. Following the canyon upstream to the "+
    "north, a great waterfalls may be seen, complete with rainbow. "+
    "To the west and south can be seen an immense forest, "+
    "stretching for miles around. A path leads north and "+
    "southwest. It is possible to climb down into the canyon from "+
    "here."));
    set("exits", ([
        "southwest" : AREA1("a1forest21.c"),
        "north" : AREA1("a1forest18.c"),
        "down" : AREA1("a1forest24.c"),
    ]) );
    set("item_desc", ([
    "canyon" : "You see nothing special about the canyon.\n",
    "river" : "It seemd to flow from a great cavern far south.\n",
    "mountains" : "Great jagged peaks, far to the east.\n",
    "waterfall" : "Huge and majestic falls.\n",
    ]) );
    set("search_desc", ([
    ]) );
}

/* EOF */
