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
You are standing on a rocky, uneven path on the side of a mountain. 
Vegetation grows alongside the path, stunted by the salt-filled air and 
apparent lack of sunlight. There is a noticable constant roar, far in the
distance. Up ahead, the path seems to bend to the right around the 
mountainside.
EndText
    );
    set("author", "cyanide");
    set("short", "An Uneven Mountain Path");
    set("exits", ([
      "south" : AREA1("a1path04.c"),
      "north" : AREA1("a1path06.c"),
    ]) );
    set("item_desc", ([
      "cliff" : "It is very high up, and a vast ocean lay at its bottom.\n",
      "ocean" : wrap("Its waters are very rough, and waves crash "+
	"against the cliff bottom."),
      "sky" : "It seems that a storm is brewing.\n",
      "vegetation" : "It consists mainly of hearty grasses.\n",
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
      "roar" : "It sounds like a huge waterfall, off to the northeast.\n",
      "default" : wrap("You hear a constant roaring in the distance to "+
	"the northeast. It grows louder as you move closer."),
    ]) );
}

/* EOF */
