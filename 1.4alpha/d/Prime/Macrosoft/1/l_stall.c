// Cyanide, 4 Aug 99

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A lady's stall");
    set("long", wrap(
	"You are inside one of the graffitti covered stalls. There "+
	"very little here except a toilet, and a toilet paper "+
	"dispenser."
      ) );
    set("exits", ([
      "north" : FLOOR_1("lady_room"),
    ]) );
    set("item_desc", ([
      "graffitti" : wrap("It reads: A woman has the last say in any "+
	"argument. Anything a man says after that is the "+
	"beginning of a new argument."),
      "toilet" : "Its quite disgusting, really.\n",
      "dispenser" : "It seems to be empty (of course)\n",
    ]) );
    set("smell", "It smells like a bathroom. Phew!\n");
    set("objects", ([ "woman" : MS_MON("pottywoman.c") ]) );
reset();
}

/* EOF */
