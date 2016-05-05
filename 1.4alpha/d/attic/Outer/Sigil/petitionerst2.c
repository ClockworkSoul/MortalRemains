#include "sigil.h"
#include <mudlib.h>

object portal;

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid());
    set ("light", 1) ;
    set("short", "Petitioner's Square, Lady's Ward.") ;
    set("long", @ENDLONG
You are in Petitioner's Square in the Lady's Ward of Sigil, where what
passes for law in Sigil is kept. 
The Courthouse is to the east, an Armory is to the west, and the imposing
Tower of the Wyrm rises to the south.
ENDLONG
    );
    set ("exits", ([
      "north" : SIGIL+"petitionerst1.c",
      "south" : SIGIL+"wyrmtower.c",
      "east" : SIGIL+"court.c",
      "west" : SIGIL+"armory.c" ]));
}

void reset() {
    ::reset();
    seteuid(getuid());
    if (!portal) {
	portal = clone_object(OBJ(drac_portal)); 
	portal->move(this_object());
    }
}
