/*
** File:  /u/n/nemar/water/city/rooms/square4.c
** Author:  Lord Nemar of the Shadoweirs
*/

#include <config.h>
#include "eloria.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid() );
    set("light", 1 );
    set("author", "Nemar" );
    set("short", "Mapleleaf Square" );
    set("long", @EndText
    You have reached the western edge of Mapleleaf Square.
    You see a beautifully crafted fountain.  It appears as if the
    water has no basin but flows into a pool of air.  The
    buildings are wonderfully colored.
EndText
    );
    set("exits", ([
      "north" : eloria+"square1.c",
      "west" : eloria+"central1a.c",
      "south" : eloria+"square6.c",
    ]) );
    set("item_desc", ([
      "ground" : "The street is made right out of the ocean floor.\n",
      "street" : "The street is made right out of the ocean floor.\n",
      "buildings" : "The buildings are made of coral.\n",
      "walls" : "The building walls are made of coral.\n",
    ]) );
}
