// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", RD_Y);
    set("long", wrap(
	"The concrete sidewalk here is broken and crumbled, and weeds "+
	"push from between the cracks. Vacant lots, once playgrounds "+
	"for children, now are fenced off and overgrown. To the west, "+
	"down a few stairs, is a small dive bar known as 'The Bitter "+
	"End', known for having the best beer in the city. To the east "+
	"is a small abandoned apartment building."
      ) );
    set("exits", ([
      "east" : "/d/Prime/Crackhouse/room/entrance.c",
      "west" : M_ROOM+"bitterend.c",
      "north" : M_ROOM+"road0_0.c",
      "south" : M_ROOM+"road0_-2.c",
    ]) );
    set("item_desc", ([
      "sidewalk" : "Not well maintained, it owuld seem.\n",
      "weeds" : "Some kind of very hardy grass. With thorns.\n",
      "lots" : "They have been fenced off and protected by bardbed wire.\n",
      "fence" : "A rusty chain link fence.\n",
      "bar" : "You hear the sounds of revelry coming from inside.\n",
      "building" : "The door seems to be slightly ajar.\n",
    ]) );
   ::create() ;
   reset() ; 
}

// EOF
