/*
** File /u/n/nemar/water/city/rooms/square3.c
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
You have reached the northeastern edge of the square.  You see
a beautifully crafted fountain.  It appears as if the water has no basin,
flows into a pool of air.  It is an amazing design.  The building walls
are very colorful.
EndText
    );
    set("exits",([
      "west" : eloria+"square2.c",
      "south" : eloria+"square5.c",
    ]) );
    set("item_desc", ([
      "ground" : "The street is made right out of the ocean floor.\n",
      "stree" : "The street is made right out of the ocean floor.\n",
      "buildings" : "The builds are made of coral.\n",
      "walls" : "The building walls are made of coral.\n",
    ]) );
}
