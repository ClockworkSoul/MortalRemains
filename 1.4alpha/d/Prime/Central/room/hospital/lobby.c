// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 27 June 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("safe", 1);
    set("light", 1);
    set("short", CITY_NAME+" Hope Hospital");
    set("long", wrap(
	"You have entered the main lobby of "+query("short")+", which "+
	"by most accounts is a standard hospital: understaffed, "+
	"underfinanced, and overburdened. To "+
	"the west is Emergency, and to the east is the Cyberware "+
	"Clinic, where one can have all manner of cyberware installed."
      ) );
    set("exits", ([
      "west" : M_ROOM+"hospital/ER.c",
      "east" : M_ROOM+"hospital/clinic.c",
      "south" : M_ROOM+"road1_0.c",
    ]) );
    set("item_desc", ([
    ]) );
}

// EOF
