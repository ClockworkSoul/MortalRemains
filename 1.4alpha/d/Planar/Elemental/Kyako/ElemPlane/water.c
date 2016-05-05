/*
// The first room in mini-water elemental plane
*/

#include <mudlib.h>
#include "plane.h"

inherit ROOM;

void create()
{
  ::create();
   seteuid(getuid());
   set( "light", 1 );
   set("short","Small beach");
   set( "long", @EndText
It turns out that it is not an endless ocean,
but there is a small sandbar that you can walk on.
EndText
  );
  set( "exits", ([
    "south"   : PLANE+"beach.c",
    "hallway" : PLANE+"firstrm.c",
  ]) );
}
