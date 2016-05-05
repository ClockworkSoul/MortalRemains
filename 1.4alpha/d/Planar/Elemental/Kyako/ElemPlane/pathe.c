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
   set("short","East of Beach");
   set( "long", @EndText
You are on a small path running from the beach.
EndText
  );
  set( "exits", ([
    "west" : PLANE+"beach.c",
    "east" : PLANE+"pathe2.c",
  ]) );
}
