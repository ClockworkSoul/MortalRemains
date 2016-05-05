/*
** File: /d/Ocean/Eloria/central1a.c
** Author:  Lord Nemar Tel'Narin of the Shadoweir
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
    set("short", "Shark Way");
    set("long", @EndText
You are near the square.  You can see a fountain in the distance
to the east.  The the north you can see a store of some sort, and
to the south you see a tavern.  You can see many other
businesses lineing the stree towards the west.
EndText
    );
    set("exits", ([
      "north" : eloria+"store.c",
      "east" : eloria+"square4.c",
      "south" : eloria+"monk_bar.c",
      "west" : eloria+"central2a.c",
    ]) );
    set("item_desc", ([
      "ground" : "The street is made right out of the ocean floor.\n",
      "street" : "The street is made right out of the ocean floor.\n",
      "buildings" : "The buildings are made of coral.\n",
      "walls" : "The building walls are made of coral.\n",
      "store" : "It looks like a store.  Why not take a closer look?\n",
      "tavern" : "It looks just like all the other taverns you've seen.  Go in!\n",
      "pub" : "It looks like every other pub you've ever seen.  Go inside!\n",
    ]) );
}
