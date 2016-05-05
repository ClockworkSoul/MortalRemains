/*
** File /u/n/nemar/rd/city/rooms/square1.c
** Author: Lord Nemar of the Shadoweirs
*/

#include <config.h>
#include "eloria.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "nemar" );
    set( "short", "Mapleleaf Square" );
    set( "long", @EndText
You have reached teh northwest corner of Mapleleaf Square.  You
see a beautifully crafted fountain.  It appears as if the water has
no basin but flows into a pool of air.  The building walls look strange.
EndText
    );
    set( "exits", ([
      "east" : eloria+"square2.c",
      "south" : eloria+"square4.c",
    ]) );
    set("item_desc", ([
      "ground" : "The stree is made right out of the ocean floor.\n",
      "street" : "The street is made right out of the ocean floor.\n",
      "buildings" : "The buildings are made of coral.\n",
    ]) );
}
