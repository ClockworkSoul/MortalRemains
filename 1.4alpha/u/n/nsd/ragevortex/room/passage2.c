/*
** File: passage2.c
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
There are stains on the floor and walls. The passage takes an
angled turn here. This passage has only two exits.
EndText
    );
    set( "exits", ([
      "east" : MINA_ROOM+"room5.c",
      "south" : MINA_ROOM+"passage1.c",
    ]) );
    set("item_desc", ([
      "electrodes" :
      "Flashy electric balls stuck to the walls and wired together.\n",
      "scratches" : "The scratches seem more like markings to you.\n",
      "walls" :
      "The walls are made of solid metal. Yet they are scratched\n"+
      "and dented.\n",
      "stains" : "They appear to be dried blood but who knows...\n",
      "markings" :
      "Bull shaped markings and scratches. It seems to be\n"+
      "some kind of writing.\n",
      "writing" :
      "You cannot decipher what it says. The language is like no other.\n",
    ]) );
}
