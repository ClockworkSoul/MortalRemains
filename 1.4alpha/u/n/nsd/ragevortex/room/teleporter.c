/*
** File: teleporter.c
** Author: Ragevortex
** Updated by: Lady Nsd (august 2000)
*/

#include <config.h>
#include <mudlib.h>
#include "mina.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Teleporter" );
    set("author", "ragevortex");
    set("long", @EndText
As you enter the teleporter you begin to float in a wierd energy field.
You hear a crackling sound and what appears to be portals suddenly form
all around you. Perhaps you could go through them.
EndText
    );
    set( "exits", ([
      "south" : MINA_ROOM+"entrance.c",
      "north" : MINA_ROOM+"room1.c",
      "east" : MINA_ROOM+"room3.c",
      "west" : MINA_ROOM+"room2.c",
    ]) );
}
