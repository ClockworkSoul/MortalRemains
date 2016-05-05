/*
** File: scndfloor4.c
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
You are in the southwest corner of the second floor. The passage
continues to southeast and north. The walls are a little dusted.
EndText );
    set( "exits", ([
      "north" : ARV_ROOM+"scndfloor3.c",
      "southeast" : ARV_ROOM+"scndfloor5.c",
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
