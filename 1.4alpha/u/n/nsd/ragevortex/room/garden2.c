/*
** File: garden2.c
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
    set("short", "Fountain");
    set("author", "ragevortex");
    set( "long", @EndText
This is an amazingly beautifull garden. Filled with trees and plants.
You stand in fron of a beautifully carved stone fountain.
The water of the fountain splashes rythmically with an
almost enchanting sound.
EndText
    );
    set( "exits", ([
      "east" : MINA_ROOM+"garden.c",
    ]) );
    set("item_desc", ([
      "tree" :
      "A huge oak tree, it has flowers and small plants climbing\n"+
      "up though it. It also looks very old.\n",
      "flowers" :
      "Beautifull flowers of many colors. This garden is well attended.\n",
      "garden" : "It's a garden. Never seen one before?\n",
      "water" : "Crystal clear water, refreshingly wet.\n",
      "fountain" :
      "A beautifully carved fountain with fresh splashy water.\n",
      "carvings" :
      "The fountain has been carved out of stone and adorned of\n"+
      "animal carvings.\n",
    ]) ); 
}
