/*
** File /u/n/nemar/water/city/rooms/squre2.c
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
    set("author", "nemar" );
    set("short", "Mapleleaf Square");
    set("long", @EndText
You have reached the northern edge of Mapleleaf Square.  You see a
beautifully crafted fountain.  It appears as if the water has no basic but
flows into a pool of air.  It is an amazing design.  The building walls
look strange.
EndText
    );
    set("exits", ([
      "east" : eloria+"square3.c",
      "west" : eloria+"square1.c",
      "north" : eloria+"main1a.c",
    ]) );
    set("item_desc", ([
      "ground" : "The street is made right out of the ocean floor.\n",
      "street" : "The stree is made right out of the ocean floor.\n",
      "buildings" : "The buildings are made of coral.\n",
      "walls" : "The building walls are made of coral.\n",
    ]) );
}
