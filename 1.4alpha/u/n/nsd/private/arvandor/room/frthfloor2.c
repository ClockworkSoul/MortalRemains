/*
** File: frthfloor2.c
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
You are in the northwest corner of the fourth floor. The
passage continues to southwest and east. The walls are a little
dusted.
EndText );
    set( "exits", ([
      "east" : ARV_ROOM+"frthfloor1.c",
      "southwest" : ARV_ROOM+"frthfloor3.c",
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
