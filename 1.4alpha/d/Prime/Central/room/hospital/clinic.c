// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 27 June 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "Cyberware Clinic");
    set("long", wrap(
	"This is a clean and legal facility, considered the best "+
	"in the area. For a price, the surgeons here can install "+
	"quality cyberware and bionics, so long as it's legal. "+
	"It appears to be abandoned at the moment."
      ) );
    set("exits", ([
      "west" : M_ROOM+"hospital/lobby.c",
    ]) );
    set("item_desc", ([
    ]) );
}

// EOF
