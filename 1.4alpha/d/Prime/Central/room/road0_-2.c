// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set ("short", RD_Y);
    set("long", wrap(
	"The reek of garbage here is almost too much to handle. "+
	"What few garbage containers there are here are overflowing, "+
	"overturned, or on fire. Graffiti covers most of the walls "+
	"here. To the west, through an wraught iron archway, is the "+
	"City Zoo. To the east there appears to be some kind of "+
	"alley or minor road, partially clogged with refuse."
      ) );
    set("exits", ([
      "west" : M_ROOM+"zooent.c",
      "north" : M_ROOM+"road0_-1.c",
      "south" : M_ROOM+"road0_-3.c",
      "east" : M_ROOM+"road1_-2.c",
    ]) );
    set("smell", "Indescribable.\n");
    set("item_desc", ([
      "refuse" : wrap("Most of it is unidentifiable. Of course, "+
	"you probably don't want to know anyway."),
      "containers" : "They read: Keep "+MUD_NAME+" Beautiful!\n",
      "archway" : "Though in need of repair, it still says 'City Zoo'.\n",
      "graffiti" : "Some of it reads: Cyanide Wuz Here, 22 May 1999\n"+
      "You wonder, who the hell is Cyanide?\n",
      "graffitti" : "It's spelled 'graffiti'. I looked it up.\n",
      "alley" : "It appears to be passable, if only barely.\n",
    ]) );
   ::create() ;
   reset() ; 
}

// EOF                                                    
