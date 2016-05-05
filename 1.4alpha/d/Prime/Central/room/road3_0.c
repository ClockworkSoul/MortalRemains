// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set ("short", RD_X);
    set("long", wrap(
	"You stand at the other edge of the Financial Quarter, still "+
	"quite clean. To the south, at the edge of the Orc District, "+
	"Is \"The Shiny Coin\", a large casino and gambling hall, and "+
	"one of the oldest buildings in the city. To the north is the "+
	"huge glass and steel building which houses the corporate "+
	"HQ of the decadant Macrosoft Corporation."
      ) );
    set("exits", ([
      "north" : "/d/Prime/Macrosoft/1/entrance.c",
      "west" : M_ROOM+"road2_0.c",
      "east" : M_ROOM+"road4_0.c",
    ]) );
    set("item_desc", ([
    ]) );
}

// EOF
