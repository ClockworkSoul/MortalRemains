/*
** File: seelietower2.c
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
You're in the second floor of the tower. Some small spider webs
hang from the walls. A stairway leads up and down. There's a
passage to the north.
EndText );
    set( "exits", ([
      "down" : ARV_ROOM+"seelietower.c",
      "up" : ARV_ROOM+"seelietower3.c",
      "north" :ARV_ROOM+"scndfloor1.c",
    ]) );
    set("item_desc", ([
      "webs" : "Ordinary spider webs.\n",
      "stairway" : "It leads up and down.\n",
    ]) );
}

/* EOF */
