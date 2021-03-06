/*
** File: thrdfloor7.c
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
You are in the hallway of the third floor. The passage continues
to northwest and south. Torches line the wall, high up in their
sconces.
EndText );
    set( "exits", ([
      "south" : ARV_ROOM+"thrdfloor6.c",
      "northwest" : ARV_ROOM+"thrdfloor8.c",
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
