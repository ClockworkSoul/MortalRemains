/*
** File: seelietower3.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Inside the tower");
    set( "long", @EndText
You're in the third floor of the tower. A tapestry of the seelie
king hangs on the wall. A stairway leads up and down. There's a
passage to the north.
EndText );
    set( "exits", ([
      "down" : ARV_ROOM+"seelietower2.c",
      "up" : ARV_ROOM+"seelietower4.c",
      "north" : ARV_ROOM+"thrdfloor1.c",
    ]) );
    set("item_desc", ([
      "tapestry" : "A tapestry of the Seelie King.\n",
      "stairway" : "It leads up and down.\n",
    ]) );
}

/* EOF */
