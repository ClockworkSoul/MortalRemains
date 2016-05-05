/*
** File: garden.c
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
    set("short", "Secret Garden");
    set("author", "ragevortex");
    set( "long", @EndText
This is an amazingly beautifull garden. Filled with trees and plants.
The walls are made of rock and covered with flowers and plants.
There's a huge tree with flowers climbing it in the middle of the room.
A fountain can be seen to the east and something shines to the west.
EndText
    );
    set( "exits", ([
      "south" : MINA_ROOM+"workroom.c",
      "east" : MINA_ROOM+"garden3.c",
      "west" : MINA_ROOM+"garden2.c",
    ]) );
    set("item_desc", ([
      "tree" :
      "A huge oak tree, it has flowers and small plants climbing up\n"+
      "though it. It also looks very old.\n",
      "flowers" :
      "Beautifull flowers of many colors. This garden is well attended.\n",
      "garden" : "It's a garden. Never seen one before?\n",
      "fountain" :
      "It's a bit far off to the east. Maybe you should go there.\n",
      "something" : "You can't figure out what it is from this distance.\n",
    ]) ); 
}
