/*
** Creator: Cyanide (27 Oct 98)
*/

#include <mudlib.h>
#include "../cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("long", @EndText
The rocky path makes a sharp bend to the right here. The roar is quite 
loud from here.
EndText
    );
    set("short", "Mountain Path Bend");
    set("author", "cyanide");
    set("exits", ([
      "south" : AREA1("a1path05.c"),
      "northeast" : AREA1("a1view02.c"),
    ]) );
    set("item_desc", ([
      "cliff" : "It is very high up, and a vast ocean lay at its bottom.\n",
      "ocean" : wrap("Its waters are very rough, and waves crash "+
	"against the cliff bottom."),
      "sky" : "It seems that a storm is brewing.\n",
      "vegetation" : "There is no real vegetation here.\n",
      "grasses" : "It's just grass.\n",
      "rocks" : "Just rocks.\n",
      "dirt" : "It is everywhere.\n",
      "ground" : "It is under you, as it should be.\n",
      "path" : "It runs from the south to the north here.\n",
      "sunlight" : "The sun is hidden behind thick cloud cover.\n",
    ]) );	
    set("search_desc", ([
      "sky" : "How the hell are you going to manage that?!\n",
      "vegetation" : "Just hearty, knotted grasses.\n",
      "climb" : "You discover that you can go up from here! (duh)\n",
      "default" : "This strikes you as pointless.\n",
    ]) );
    set("smell", ([
      "air" : "Very salty from the ocean waters at the bottom "+
      "of the cliff.\n",
      "default": wrap("The air is very salty from the ocean waters at the "+
	"bottom of the cliff."),
    ]) );
    set("listen", ([
      "roar" : "It sounds like a huge waterfall, off to the east.\n",
      "default" : wrap("There is a constant roaring coming from "+
	"somewhere to the east. From here, it is so loud you would "+
	"have to shout to be heard over it."),
    ]) );
}

/* EOF */
