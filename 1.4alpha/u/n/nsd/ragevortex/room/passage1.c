/*
** File: passage1.c
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
The metal walls seem to be covered with scratches and dents.
There are stains on the floor and walls.
This passage has only two exits.
EndText
    );
    set( "exits", ([
      "north" : MINA_ROOM+"passage2.c",
      "south" : MINA_ROOM+"room1.c",
    ]) );
    set("item_desc", ([
      "electrodes" :
      "Flashy electric balls stuck to the walls and wired together.\n",
      "scratches" : "The scratches seem more like markings to you.\n",
      "walls" :
      "The walls are made of solid metal, yet they are scratched\n"+
      "and dented.\n",
      "stains" : "It appears to be dried blood but who knows...\n",
      "markings" :
      "Bull shaped markings and scratches. They seem to be some\n"+
      "kind of writing.\n",
      "writing" : "You cannot decipher what it says. The language is\n"+
      "like no other.\n",
    ]) );
    set ("objects", ([
      "minotaur" :  MINA_MON+"minotaursmall.c",
    ]) );
    reset();
}
