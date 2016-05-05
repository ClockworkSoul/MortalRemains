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
     set ("objects", ([ "pirate" : PLANE+"monsters/pirate",
     "pirate2" : PLANE+"monsters/pirate",
     "pirate3" : PLANE+"monsters/pirate",
     ]) );
   reset();
   set("short", "On the ship");
   set( "long", @EndText
You are now actually on the ship.
You start to get a little seasick by the rocking of the boat.
EndText
  );
  set( "exits", ([
    "off"  : PLANE+"frontship.c",
    "east" : PLANE+"cabin.c",
    "west" : PLANE+"storage.c",
  ]) );
     create_door("east","west","an iron door inscribed with a fist","locked","captkey",30);
}
