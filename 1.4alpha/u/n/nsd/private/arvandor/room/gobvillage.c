/*
** File: gobvillage.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create(){
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "A clearing");
    set( "long", @EndText
You're standing on a clearing inside the forest. This part
of the forest is full of oak trees and few pine trees.
A path leads all the way north to something that seems like
civilization.
EndText);
    set( "exits", ([
      "south" : ARV_ROOM+"forest2.c",
      "north" : ARV_ROOM+"gobvillage2.c",
    ]) );
    set("item_desc", ([
      "trees" : "Ancient and fat oak trees.\n",
    ]) );
}

/* EOF */
