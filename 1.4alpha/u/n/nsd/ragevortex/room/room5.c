/*
** File: room5.c
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
on the floor and walls.
The ever-present Teleporter is here too. Strangely
enough this room has a mural on one of the walls.
EndText
    );
    set( "exits", ([
      "west" : MINA_ROOM+"passage2.c",
      "teleporter" : MINA_ROOM+"teleporter.c",
    ]) );
    set("item_desc", ([
      "electrodes" :
      "Flashy electric balls stuck to the walls and wired together.\n",
      "walls" :
      "Made of solid metal. There are deep scratches and dents on them.\n",
      "dents" : "It looks like something was smashed rather hard here.\n",
      "mural" :
      "It depicts a huge minotaur wearing a strange looking armor\n"+
      "and wielding an axe-like wepon that appears to be made of\n"+
      "a horn from another minotaur.\n",
      "scratches" :
      "The scratches on the wall... something strong did this.\n",
      "stains" : "They seem to be dried blood.\n",
      "teleporter" :
      "It's a pannel on the a corner. It glows with crackling\n"+
      "energy. It says 'Teleporter' in flashy letters.\n",
    ]) );
    set ("objects", ([
      "minotaur" : MINA_MON+"minotaur1.c",
    ]) );
    reset();
}
