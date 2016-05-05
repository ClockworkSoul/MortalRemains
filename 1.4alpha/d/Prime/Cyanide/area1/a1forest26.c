// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

int portal = 0;

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "End of Rainbow");
    set("long", wrap("You are on a small, rocky beach on the "+
	"continuation of a great before the falls. The beach is "+
	"narrow due to the presence of the cliffs. The river canyon "+
	"opens here and sunlight shines in from above. A rainbow "+
	"crosses over the falls to the east and a narrow path "+
	"continues to the southwest."));
    set("exits", ([
      "southwest" : AREA1("a1forest25.c"),
    ]) );
    set("pre_exit_func", ([
      "east" : "rainbow",
    ]) );
    set("item_desc", ([
      "rainbow" : "Merely a beautiful optical illusion.\n",
    ]) );
    set("search_desc", ([
    ]) );
}

void init() {
    add_action("wave", "wave");
}

int rainbow() {
    write("You must be kidding, right?\n");
    return 1;
}

int wave(string str) {
    object port;

    port = clone_object(OBJ+"/rainbow.c");
    if (!port) portal = 1;

    if (str=="scepter"||str=="scepter") {
	if (present("#RAINBOW_SCEPTER#", TP)) {
	    write("You wave the scepter.\n");
	    say(TPN+" waves a ornate golden scepter.\n");
	    if (!portal) {
		tell_room(TO, ("Suddenly, the rainbow "+
		    "coalesces into solidity!\n"));
		port->move(TO);
	    } else {
		tell_room(TO, ("Nothing happens.\n"));
	    }
	    return 1;
	}
    } 

    return 0;
}

/* EOF */
