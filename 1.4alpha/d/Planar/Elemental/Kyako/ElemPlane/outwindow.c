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
   set("short","Outside Mayor's window");
   set( "long", @EndText
You come out of the window, and end up on a small sandbar not unlike
the one you encountered when you first entered this area.
Unfortunately, the window you came out of locks with a small click.
It looks like you're going to have to exit through the hole.
EndText
  );
  set( "exits", ([
    "down" : PLANE+"cave1.c",
  ]) );
}
