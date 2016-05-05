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
   set("objects", (["mate" : PLANE+"monsters/matesilv" ]) );
   reset();
   set("short","In front of ship");
   set( "long", @EndText
You are standing in front of a ship.
You see many pirates walking around,
bringing things on and off the ship.
EndText
  );
  set( "exits", ([
    "ship"  : PLANE+"ship.c",
    "east"  : PLANE+"eastship.c",
    "north" : PLANE+"beach.c",
  ]) );
}
