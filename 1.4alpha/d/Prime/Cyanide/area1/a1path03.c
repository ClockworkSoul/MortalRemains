/*
** Creator: Cyanide (28 Jan 98)
*/

#include <mudlib.h>
#include "../cy.h"

inherit ROOM;

void create() {
    ::create();
    set("light", 1);
    set("long", @EndText
You are standing on a rocky, uneven path. Vegetation grows alongside the 
path, stunted by the salt-filled air and apparent lack of sunlight. To the
southwest, the path seems to get much closer to the ocean, and the path
continues to the north. There seems to be a pass into the mountains to the
east.
EndText
    );
    set("author", "cyanide");
    set("short", "An Uneven Mountain Path");
    set("exits", ([
      "southwest" : AREA1("a1view01.c"),
      "east" : AREA1("a1pass01.c"),
      "north" : AREA1("a1path04.c"),
    ]) );
    set("smell", ([
      "air" : "Very salty from the ocean waters at the bottom "+
      "of the cliff.\n",
      "default": wrap("The air is very salty from the ocean waters at the "+
	"bottom of the cliff."),
    ]) );
    set("listen", ([
      "default" : "You hear a constant roaring in the distance to "+
      "the northeast.\n",
    ]) );
    set("item_desc", ([
      "sky" : "It seems that a storm is brewing.\n",
      "vegetation" : "It consists mainly of hearty grasses.\n",
      "grasses" : "It's just grass.\n",
      "rocks" : "Just rocks.\n",
      "path" : "It leads to the north and southwest.\n"
    ]) );

}

/* EOF */                              
