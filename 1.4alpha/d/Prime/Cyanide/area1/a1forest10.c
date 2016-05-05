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
    set("long", wrap("You are on an overgrown path in a dimly lit "+
        "forest. Here, on the edge of a large thicket, thorny vines "+
        "pull at your clothing and scratch your skin. To the east, "+
        "through the thick foliage, you can barely make out some "+
        "kind of wooden structure built in the branches of a huge "+
        "oak."));
    set("exits", ([
        "northeast" : AREA1("a1forest05.c"),
        "west" : AREA1("a1treebtm.c"),
    ]) );
    set("item_desc", ([
    "oak" : "It is truly ancient - hundreds of years old, perhaps.\n",
    "path" : "It leads to the east and northeast.\n",
    "thicket" : "A huge mass of thorns. Utterly impassable.\n",
    "vines" : "All covered with inch-long thorns.\n",
    "skin" : "Want some private time?\n",
    "structure" : "It looks like a treehouse.\n",
    ]) );
    set("search_desc", ([
    ]) );
    set("smell", ([
    ]) );
}

/* EOF */
