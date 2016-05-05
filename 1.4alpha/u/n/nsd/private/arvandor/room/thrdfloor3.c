/*
** File: thrdfloor3.c
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
You are in the hallway of the third floor. The passage continues to
to south and northeast. Torches line the wall, high up in their
sconces.
EndText );
    set( "exits", ([
      "northeast" : ARV_ROOM+"thrdfloor2.c",
      "south" : ARV_ROOM+"thrdfloor4.c",
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
