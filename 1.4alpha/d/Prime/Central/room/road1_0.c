// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", RD_X);
    set("long", wrap(
	"You are at the beginning of "+RD_X+", which heads east from "+
	"here. It is noticibly cleaner around these non-residential "+
	"areas, and the Financial Quarter lay closely to the east. "+
	"You notice most of the populace here are human, dwarves, "+
	"and gnomes, almost exclusively."+
	"\nTo the direct north is "+CITY_NAME+" Hope, the regional "+
	"hospital. Ironically, to the south, on the edge of the Orc "+
	"District, is the bloody arena, where people come to settle "+
	"old grudge matches."
      ) );
    set("exits", ([
      "north" : M_ROOM+"hospital/lobby.c",
      "south" : M_ROOM+"arena.c",
      "west" : M_ROOM+"road0_0.c",
      "east" : M_ROOM+"road2_0.c",
    ]) );
    set("item_desc", ([
    ]) );
}

// EOF
