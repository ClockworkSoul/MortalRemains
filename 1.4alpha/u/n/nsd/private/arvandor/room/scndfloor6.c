/*
** File: scndfloor6.c
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
You are in the southeast corner of the second floor. The passage
continues to north and southwest. The walls are a little dusted.
EndText );
    set( "exits", ([
      "southwest" : ARV_ROOM+"scndfloor5.c",
      "north" : ARV_ROOM+"scndfloor7.c",
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
