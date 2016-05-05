/*
// A blank room, take it to make new rooms.
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
   set("short","The room of the elemental.");
   set("objects", ([ "water" : PLANE+"monsters/mastwatelem.c" ]) );
   set( "long", @EndText
You enter what looks like a temporary palace.
It is SO wet here that it is difficult to tell that you are in a ship,
not in the ocean.
A throne of water stands here.
EndText
  );
  set( "exits", ([
    "west" : PLANE+"entfoyer.c",
  ]) );
  set( "item_desc", ([
  ]) );
  create_door("west","east","A damp, wooden door","locked","elemkey",30);
  reset();
}
