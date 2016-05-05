/*
// The first room in mini-water elemental plane
*/

#include <mudlib.h>
#include "plane.h"

inherit ROOM;
inherit DOORS;

void create()
{
  ::create();
   seteuid(getuid());
   set( "light", 1 );
   set("short","Captain's cabin");
   set( "long", @EndText
You are in the cabin of the ship.
It is very well decorated, as if
The captain had an unlimited supply of money.
EndText
  );
  set( "exits", ([
    "west" : PLANE+"ship.c",
  ]) );
     create_door("west","east","an iron door inscribed with a fist","locked","captkey",30);
}
