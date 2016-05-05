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
   set("short","West of Beach");
   set( "long", @EndText
You are on a small path running from the beach.
There is a local pub to the south.
EndText
  );
  set( "exits", ([
    "east"  : PLANE+"beach.c",
    "south" : PLANE+"waterbar.c",
  ]) );
}
