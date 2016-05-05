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
    set("long", wrap("You are in a lightly forested path near the "+
      "western edge of a large forest. The path continues into the "+
      "forest to the northeast and the south. There appears to be "+
      "some kind of structure in the trees in that direction as well."));
    set("exits", ([
        "northeast" : AREA1("a1forest02.c"),
        "south" : AREA1("a1treebtm.c"),
    ]) );
    set("item_desc", ([
    ]) );
    set("search_desc", ([
    "path" : "It leads south and northeast.\n",
    "forest" : wrap("This part of the forest os mostly oak, but some "+
        "pine as well."),
    "structure" : "Some kind of treehouse, perhaps?\n",
    ]) );
    set("smell", ([
    "default" : "The air here smells fresh and clean.\n",
    "path" : "It smells like dirt.\n",
    ]) );
}

/* EOF */
