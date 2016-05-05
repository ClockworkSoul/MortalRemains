// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Near a Chasm");
    set("long", wrap("You are walking along the northwestern edge "+
	"of a gigantic bowl-shaped chasm seemingly torn into the "+
	"earth by some massive force. A narrow and overgrown path "+
	"runs into the dark forest looming to your north."));
    set("exits", ([
      "north" : AREA1("a1forest11.c"),
      "southwest" : AREA1("a1forest04.c"),
      "east" : AREA1("a1forest16.c"),
    ]) );
    set("item_desc", ([
      "chasm" : "It looks almost like a huge crater.\n",
      "forest" : "It is quite dark and spooky.\n",
      "edge" : "It's exactly that, the edge of the crater.\n",
      "path" : "Probably a rarely used game trail.\n",
    ]) );
    set("search_desc", ([
      "chasm" : "You HAVE to be kidding?\n",
      "forest" : "You don't have that much time.\n",
      "edge" : "BORING!\n",
      "path" : "Just go north, dummy.\n",
    ]) );
    set("smell", ([
      "default" : "",
    ]) );
}

/* EOF */
