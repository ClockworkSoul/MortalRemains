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
   set("short", "Small pool");
   set( "long", @EndText
You are in an area east of the ship.
You stand in a small pool that stands up to your waist.
EndText
  );
  set( "exits", ([
    "west" : PLANE+"frontship.c",
  ]) );
}
