/*
** File: treeway.c
** Author: Lady Nsd
** Other Comments: To secure peace is to prepare for war!!! 
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
    set("short", "Over-dense forest");
    set( "long", @EndText
Too many pine trees blocking the way. You can hardly pass.
EndText );
    set( "exits", ([
      "northwest" : ARV_ROOM+"gobvillage2.c",
      "southeast" : ARV_ROOM+"forest3.c",
    ]) );
    set("item_desc", ([
      "trees" : "Broad pine trees full of branches.\n",
    ]) );
}

/* EOF */
