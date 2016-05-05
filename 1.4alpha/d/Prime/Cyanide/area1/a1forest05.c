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
    set("long", wrap("You are on a path in the forest, in an area "+
	"where oak trees seem to dominate. The path here leads from "+
	"the northwest, and continues to the southeast, where it twists "+
	"its way around a huge, blackened stump."));
    set("exits", ([
      "southeast" : AREA1("a1forest08.c"),
      "northwest" : AREA1("a1forest02.c"),
      "southwest" : AREA1("a1forest10.c"),
    ]) );
    set("item_desc", ([
      "stump" : "That's a bit furth southeast.\n",
      "ground" : "It seems to get a bit more wet to the east and south.\n",
    ]) );
    set("search_desc", ([
      "stump" : "You're still too far away.\n",
    ]) );
    set("smell", ([
      "default" : "It's starting to smell a bit damp and loamy here.\n",
    ]) );
}

/* EOF */
