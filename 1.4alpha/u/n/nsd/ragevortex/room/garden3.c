/*
** File: garden3.c
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
    set("short", "Statue");
    set("author", "ragevortex");
    set( "long", @EndText
This is an amazingly beautifull garden. Filled with trees and plants.
In the middle of this room there's a golden statue of a woman.
This garden part is really preety with roses and preety stones.
EndText
    );
    set( "exits", ([
      "west" : MINA_ROOM+"garden.c",
    ]) );
    set("item_desc", ([
      "flowers" :
      "Beautifull flowers of many colors. This garden is well attended.\n",
      "roses" :
      "Red, yellow, and white roses... all in full bloom.\n",
      "statue" :
      "A statue made of gold. It is a woman on a long dress with\n"+
      "long hair and sitting on a dolphin.\n",
      "dolphin" :
      "It's a statue of a dolphin. It's the woman's steed.\n"+
      "There's a plaque here.\n",
      "plaque" :
      "It reads- In honor to the goddess of the secret garden, may all\n"+
      "who see her, dream with this place forever.\n",
      "stones" :
      "The floor is tiled with tiny little stones of many colors.\n",
    ]) ); 
}
