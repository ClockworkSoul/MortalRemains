// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "By A Giant Anthill");
    set("long", wrap("You are standing next to a huge mound "+
	"of sand, which surrounds a great hole in the ground. You "+
	"hear the sounds of scurrying and digging from below.") );
    set("exits", ([
      "southeast" : AREA1("a1forest03.c"),
      "down" : ANTHILL("ants6.c"),
    ]) );
    set("item_desc", ([
      "hole" : "It leads down, into darkness.\n",
      "sand" : "It seems to have been moved here.\n",
      "mound" : "It looks like a giant anthill.\n",
    ]) );
    set("search_desc", ([
      "sand" : "You just find more sand.\n",
    ]) );

    find_object_or_load(ANTHILL("ants27.c"));
}

/* EOF */
