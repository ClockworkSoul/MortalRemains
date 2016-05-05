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
As you come around the bend, you come upon an incredible view. High above
you, a huge waterfall crests the top of the cliff, and falls hundreds of
feet to crash into the ocean waters below.
The cliff ledge becomes impassably narrow to the east.
EndText
    );
    set("short", "Waterfall View");
    set("author", "cyanide");
    set("exits", ([
      "west" : AREA1("a1path06.c"),
    ]) );
    set("item_desc", ([
      "cliff" : wrap("It is very high up, and appears to be forested "+
	"at its plateau."),
      "waterfall" : wrap("It is a majestic natural phenomenon, and is "+
	"easily five hundred feet in height. The river on the plateau "+
	"must be quite large."),
      "ocean" : wrap("Its waters are very rough, made rougher by "+
	"the waterfall."),
      "sky" : "It seems that a storm is brewing.\n",
      "vegetation" : "There is no real vegetation here.\n",
      "dirt" : "It is everywhere.\n",
      "ground" : "It is under you, as it should be.\n",
      "path" : wrap("It runs from around the mountain to the west, to "+
	"the east. The path to the east is impassable, however."),
      "bend" : "It's nothing special, really.\n",
      "sunlight" : "The sun is hidden behind thick cloud cover.\n",
      "ledge" : "It becomes narrow and devoid of vegetation here.\n",
    ]) );	
    set("search_desc", ([
      "sky" : "How the hell are you going to manage that?!\n",
      "vegetation" : "The cliff is devoid of vegetation.\n",
      "default" : "This strikes you as incredibly pointless.\n",
    ]) );
    set("smell", ([
      "air" : "Very salty from the ocean waters at the bottom "+
      "of the cliff.\n",
      "default": wrap("The air is very salty from the ocean waters at the "+
	"bottom of the cliff."),
    ]) );
    set("listen", ([
      "roar" : "It is from the waterfall, of course.\n",
      "default" : wrap("There is a constant roaring coming from "+
	"somewhere to the east. From here, it is so loud you would "+
	"have to shout to be heard over it."),
    ]) );
}

/* EOF */
