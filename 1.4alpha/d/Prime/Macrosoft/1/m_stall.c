// Cyanide, 4 Aug 99

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A men's stall");
    set("long", wrap(
	"You are inside one of the graffitti covered stalls. There "+
	"very little here except a toilet, and a toilet paper "+
	"dispenser."
      ) );
    set("exits", ([
      "south" : FLOOR_1("men_room"),
    ]) );
    set("item_desc", ([
      "graffitti" : wrap("It reads: The difference between "+
	"ignorance and apathy?  I don't know, and I "+
	"couldn't care less..."),
      "toilet" : "Its quite disgusting, really.\n",
      "dispenser" : "It seems to be empty (of course)\n",
    ]) );
    set("smell", "It smells like a bathroom. Phew!\n");
    set("objects", ([ "man" : MS_MON("pottyman.c") ]) );
reset();
}

/* EOF */
