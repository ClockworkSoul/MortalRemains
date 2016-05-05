#include <mudlib.h>
#include "main.h"

inherit MAIN+"/LOSmain.c";

void create()
{
    ::create();
    set ("short", "Land of Shadow");
    set( "long", @EndText
You are in a dark and shadowy land. All around you are gentle hills and
eerie shadows. Far above, shrouded in mist, you can barely make out the
ceiling of the enormous cavern that spans this entire land.
EndText
    );
    set( "exits", ([
      "east" : MAIN+"/LOS01.c",
      "south" : MAIN+"/LOS04.c",
      "southwest" : MAIN+"/LOS06.c",
      "northwest" : MAIN+"/LOS08.c",
      "north" : MAIN+"/LOS02.c",
    ]) );
    set ("exit_suppress", ([
    ]) );

    set ("item_desc", ([
      "ceiling" : "You can barely make it out in the dim light.\n",
      "mist" : "Well, now how do you propose to do that?\n",
    ]) );
}

