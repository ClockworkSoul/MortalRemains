/*
** File: gobvillage2.c
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
    set("short", "A clearing");
    set( "long", @EndText
The path continues to the north. Oak trees border all the way.
From beneath the trees, you can distinguish something that
seems like a cottage. A rustic one, off course. You wonder if
many people know of this place.
EndText);
    set( "exits", ([
      "south" : ARV_ROOM+"gobvillage.c",
      "north" : ARV_ROOM+"gobvillage3.c",
      "southeast" : ARV_ROOM+"treeway.c",
    ]) );
    set("item_desc", ([
      "trees" : "Ancient and fat oak trees.\n",
      "cottage" : "Not from here. You have to walk a little more.\n",
    ]) );
}

/* EOF */
