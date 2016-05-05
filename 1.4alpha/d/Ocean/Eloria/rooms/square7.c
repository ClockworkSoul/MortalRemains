/*
** File: /u/n/nemar/water/city/rooms/square7.c
** Author:  Lord Nemar of the Shadoweir
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
You have reached the southern edge of Mapleleaf Square.  You
see a beautifully crafted fountain.  It appears as if the water has
no basin, but flows into a pool of air.  It is an amazing design.
The building walls look strange, yet colorful.
EndText
    );
    set("exits", ([
      "west" : eloria+"square6.c",
      "east" : eloria+"square8.c",
      "south" : eloria+"main1b.c",
    ]) );
    set("item_desc", ([
      "ground" : " The street is made right out of the ocean floor.\n",
      "street" : "The street is made right out of the ocean floor.\n",
      "buildings" : "The buildings are made of coral.\n",
      "walls" : "The building walls are made of coral.\n",
    ]) );
}
