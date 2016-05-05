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
   set("short","Large Beach");
   set( "long", @EndText
You now realize that this is an island.
To the south, you see a ship docked.
A small path runs to the east and west.
EndText
  );
  set( "exits", ([
    "west"  : PLANE+"pathw.c",
    "east"  : PLANE+"pathe.c",
    "south" : PLANE+"frontship.c",
    "north" : PLANE+"water.c",
  ]) );
}
