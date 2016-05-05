/*
** File: thrdfloor4.c
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
You are in the southwest corner of the third floor. The passage
continues to southeast and north. The walls are a little dusted.
EndText );
    set( "exits", ([
      "north" : ARV_ROOM+"thrdfloor3.c",
      "southeast" : ARV_ROOM+"thrdfloor5.c",
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
