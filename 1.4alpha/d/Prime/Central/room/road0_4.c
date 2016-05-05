// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", RD_Y);
    set("long", wrap(
	"Eventually, the organic buildings of the Elven District "+
	"give way to the flawlessly constructed granite structures "+
	"of the Dwarven District. Though not quite as clean as the "+
	"elves, there is almost no trash here to speak of."
      ) );
    set("exits", ([
      "north" : M_ROOM+"road0_5.c",
      "south" : M_ROOM+"road0_3.c",
    ]) );
    set("item_desc", ([
    ]) );
   ::create() ;
   reset() ; 
}

// EOF
