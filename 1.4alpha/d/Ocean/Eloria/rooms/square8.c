/*
** File: /u/n/nemar/water/city/rooms/square8.c
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
    set("author", "Nemar");
    set("short", "Mapleleaf Square");
    set("long", @EndText
You have reached the southeastern edge of Mapleleave Square. You
see a beautifully crafted fountain.  It appears as if the water has
no basin, but flows into a pool of air.  It is an amazing design.
The building walls are very colorful in a strange way.
EndText
    );
    set("exits", ([
      "north" : eloria+"square5.c",
      "west" : eloria+"square7.c",
]) );
set("item_desc", ([
      "ground" : "The street is made right out of the ocean floor.\n",
      "street" : "The street is made right out of the ocean floor.\n",
      "buildings" : "The buildings are made of coral.\n",
      "walls" : "The building walls are made of coral.\n",
    ]) );
}
