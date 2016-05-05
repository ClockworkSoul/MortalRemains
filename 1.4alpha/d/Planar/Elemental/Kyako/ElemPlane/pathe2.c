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
   set("short", "Eastern end.");
   set( "long", @EndText
You have come to the eastern end of the island.
You are amazed by the unparalleled beauty of the water.
To the north is the mayors office, to the south is the general store.
EndText
  );
  set( "exits", ([
    "west"  : PLANE+"pathe.c",
    "south" : PLANE+"shop.c",
    "north" : PLANE+"mayoroffice.c",
  ]) );
     create_door("north","south","An oak door","open","mayorkey",30);
}
