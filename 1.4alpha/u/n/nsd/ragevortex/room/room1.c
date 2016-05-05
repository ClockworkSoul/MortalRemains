/*
** File: room1.c
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
This closed room has electrodes on it's metal walls. There's a
stench in here. The metal walls seem to be covered with scratches
and dents. There are stains on the floor and walls. In front of
each wall there's a flashing plaque with the word "Teleporter"
on them.
EndText
    );
    set( "exits", ([
      "north" : MINA_ROOM+"passage1.c",
      "teleporter" : MINA_ROOM+"teleporter.c",
    ]) );
    set("item_desc", ([
      "electrodes" :
      "Flashy electric balls stuck to the walls and wired together.\n",
      "walls" :
      "Made of solid metal. There are deep scratches and dents on them\n",
      "dents" : "They look as if something was smashed rather hard here.\n",
      "pannel" : "This is the teleporting floor pannel.\n",
      "scratches" :
      "The scratches on the wall... something strong did this.\n",
      "stains" : "They seem to be dried blood.\n",
      "teleporter" :
      "It's a pannel on the a corner. It glows with crackling energy.\n"+
      "It says 'Teleporter' in flashy letters.\n",
    ]) );
}
