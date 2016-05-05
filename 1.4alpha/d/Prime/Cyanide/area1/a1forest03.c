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
    set("long", wrap("You are standing on a path in a dimly lit "+
	"forest. The trees seems to thin out a bit to the "+
	"northeast, and you see what looks like a giant mound "+
	"of dirt to the northwest."));
    set("exits", ([
      "northwest" : AREA1("a1forest27.c"),
      "south" : AREA1("a1forest01.c"),
      "northeast" : AREA1("a1forest06.c"),
    ]) );
    set("item_desc", ([
      "mound" : "It looks like a giant anthill.\n",
    ]) );
    set("search_desc", ([
    ]) );
}

/* EOF */
