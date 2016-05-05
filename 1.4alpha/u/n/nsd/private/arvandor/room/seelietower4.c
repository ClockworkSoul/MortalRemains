/*
** File: seelietower4.c
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
You're in the fourth floor of the tower.  There are some swords
adorning the chamber walls. A stairway leads up and down.
There's a passage to the north.
EndText );
    set( "exits", ([
      "down" : ARV_ROOM+"seelietower3.c",
      "up" : ARV_ROOM+"branches.c",
      "north" : ARV_ROOM+"frthfloor1.c",
    ]) );
    set("item_desc", ([
      "swords" : "Symbolic swords made of gold that serve as ornament only.\n",
      "stairway" : "It leads up and down.\n",
    ]) );
}

/* EOF */
