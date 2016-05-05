/*
** File: room7.c
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
There's a stench in here. The metal walls seem to be
covered with scratches and dents. There are stains
on the floor and walls. In front of each wall, there's
a flashing plaque with the word "Teleporter" on it.
There's a mural here ...
EndText
    );
    set( "exits", ([
      "north": MINA_ROOM+"room3.c",
      "teleporter" : MINA_ROOM+"teleporter.c",
    ]) );
    set("item_desc", ([
      "electrodes" :
      "Flashy electric balls stuck to the walls and wired together.\n",
      "walls" :
      "Made of solid metal. There are deep scratches and dents on them.\n",
      "stains" : "They seem to be dried blood.\n",
      "mural" :
      "On this wall there's a mural, the picture is all blurred and\n"+
      "it has an inscription.\n",
      "inscription" :
      "This inscription is unreadable to you, the characters\n"+
      "are of an unknown origin and you cannot read them.\n",
      "teleporter" :
      "It's a pannel on the corner. It glows with crackling energy.\n"+
      "It says 'Teleporter' in flashy letters.\n",
    ]) );
    set ("objects", ([
      "minotaur" : MINA_MON+"minotaur1.c",
    ]) );
    reset();
}
