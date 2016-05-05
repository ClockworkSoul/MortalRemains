/*
** File: /u/n/nemar/water/city/rooms/square5.c
** Author:  Lord Nemar of the Shadoweirs
*/

#include <config.h>
#include "eloria.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid() );
    set("light", 1);
    set("author", "nemar");
    set("short", "Mapleleaf Square");
    set("long", @EndText
You have reached the eastern edge of Mapleleaf Square.  You
see a beautifully crafted fountain.  I appears as if the water has
no basin, but flows into a pool of air.  It is an amazing design.
The building walls are very colorful.
EndText
    );
    set("exits",([
      "north" : eloria+"square3.c",
      "east" : eloria+"central1b.c",
      "south" : eloria+"square8.c",
    ]) );
    set("item_desc", ([
      "ground" : "The street is made right out of the ocean floor.\n",
      "street" : "The street is made right out of the ocean floor.",
      "buildings" : "The buildings are made of coral.\n",
      "walls" : "The building walls are made of coral.\n",
    ]) );
}
