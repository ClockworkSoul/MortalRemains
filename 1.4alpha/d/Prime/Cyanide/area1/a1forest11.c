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
    set("long", wrap("The forest here is a thick mixture of oak "+
    "and pine, competing for the meager sunlight. The main path "+
    "runs east and west through the trees, and a narrow, overgrown "+
    "path is barely visible through the underbrush to the south. "+
    "To the north. the trees thin out a bit, exposing a large and "+
    "crumbling stone wall. A collapsed portion of the wall grants "+
    "access to whatever lies beyond."));
    set("exits", ([
        "north" : AREA1("a1forest09.c"),
        "west" : AREA1("a1forest06.c"),
        "east" : AREA1("a1forest17.c"),
        "south" : AREA1("a1forest12.c"),
    ]));
    set("item_desc", ([
    "sunlight" : "You haven't seen much of that lately.\n",
    "oak" : "They are more common to the west.\n",
    "pine" : "The dominate further east.\n",
    "path" : "Which one?\n",
    "east path" : "It runs east, into the pines.\n",
    "west path" : "It runs west, into the oaks.\n",
    "south path" : "Apparently, a rarely used game trail.\n",
    "trees" : "There are an awful lot of them here...\n",
    "wall" : wrap("It's just a wall, without a roof. It is "+
       "constructed of several large, weathered granite blocks."),
    "blocks" : "That doesn't appear to be native stone.\n",
    "portion" : "It looks like it has been smashed outward.\n",
    "engraving" : "It reads: \"Cyanide was here. 11 Nov 98.\"\n"+
        "Cryptic, isn't it?\n",
    ]) );
    set("search_desc", ([
    "wall" : "A small engraving is etched into one of the "+
        "stones.\n",
    ]) );
    set("smell", ([
    "default" : "You smell salt in the air, you think.",
    ]) );
}

/* EOF */
