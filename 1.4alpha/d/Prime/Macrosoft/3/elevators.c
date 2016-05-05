// Cyanide coded this.

#include "macrosoft.h"

inherit MS_ELEV;

object mitch;

void create() {
    ::create();
    set("exits", ([ 
      "north" : FLOOR_3("hall2.c"),
      "south" : FLOOR_3("hall6.c"),
    ]) );
    set("floor", 3);

    if (!mitch) {
	mitch = clone_object( MS_MON("mitch.c") );
	mitch->move(TO);
    }
}

/* EOF */
