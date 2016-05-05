/*
** File: room3.c
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
    set( "short", "Laberinth" );
    set("author", "ragevortex");
    set( "long", @EndText
This closed room has electrodes on it's metal walls.
There's a stench in here. The metal walls seem to
be covered with scratches and dents. There are
stains on the floor and walls. This room seems to be
the same as the others, yet there's something different.
In front of each wall there's a flashing plaque with
the word "Teleporter" on it.
EndText
    );
    set( "exits", ([
      "teleporter" : MINA_ROOM+"teleporter.c",
      "south" : MINA_ROOM+"room7.c",
    ]) );
    set("item_desc", ([
      "electrodes" :
      "Flashy electric balls stuck to the walls and wired together.\n",
      "walls" :
      "Made of solid metal. There are deep scratches and dents on them.\n",
      "stains" : "They seem to be dried blood.\n",
      "teleporter" :
      "It's a pannel on the a corner. It glows with crackling energy.\n"+
      "It says 'Teleporter' in flashy letters.\n",
    ]) );
}
