#include "main.h"

inherit MAIN+"/palacestd.c";

void create()
{
    ::create();
    set ("short", "Spire Antechamber");
    set( "long", @EndText
You are in the chamber directly beneath the spire which tops the
palace. This is a large cubic room without furniture,  dominated 
by a large black iron spiral staircase leading upwards. The walls
are covered from floor to ceiling with magnificiently painted
murals, broken only by the archways, which lead north and south
into long halls, and to the west into an opulant garden.
EndText
    );
    set( "exits", ([
      "up" : MAIN+"/spire1.c",
      "north" : MAIN+"/phallcn.c",
      "south" : MAIN+"/phallcs.c",
      "west" : MAIN+"/gpathe.c",
    ]) );
    set ("item_desc", ([
      "murals" : wrap( "They are clearly the work of a master, "+
	"and must have cost a small fourtune."),
      "walls" : "They are completely covered by the murals.\n",
      "staircase" : "It leads up into the spire.\n",
      "archways" : "There is nothing special about the archways.\n",
      "garden" : "It is beautiful, even from here.\n",
    ]) );
    set("smell", wrap("You can smell the multitude of "+
	"fragrances from the garden."));
    set("listen", wrap("You can hear the clamor as the "+
	"kitchen staff prepeares the next meal."));
}

/* EOF */
