/*
** File: room2.c
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
    set("smell", "It stinks of dried blood and rusted metal.\n");
    set( "long", @EndText
This closed room has electrodes on it's metal walls.
There's a stench and a hole in here. The hole goes down
through the floor. In front of each wall, there's a flashing
plaque with the word "Teleporter" on it.
EndText
    );
    set( "exits", ([
      "down" : MINA_ROOM+"room6.c",
      "teleporter" : MINA_ROOM+"teleporter.c",
    ]) );
    set("item_desc", ([
      "electrodes" :
      "Flashy electric balls stuck to the walls and wired together.\n",
      "walls" :
      "Made of solid metal. There are deep scratches and dents on them.\n",
      "hole" :
      "This hole goes down to another floor. You can't see from here.\n",
      "stains" : "They seem to be dried blood but who knows...\n",
      "teleporter" :
      "It's a pannel on a corner. It glows with crackling Energy.\n"+
      "It says 'Teleporter' in flashy letters.\n",
    ]) );
}
