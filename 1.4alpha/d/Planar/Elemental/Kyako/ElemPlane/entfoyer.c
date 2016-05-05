/*
// A blank room, take it to make new rooms.
*/

#include <mudlib.h>
#include "plane.h"

inherit ROOM;
inherit DOORS;

void create()
{
   seteuid(getuid());
   set("objects", ([ "water elemental" : PLANE+"monsters/waterelem.c",
   ]) );
   set( "light", 1 );
   set("short","The entrance foyer.");
   set( "long", @EndText
You stand in what looks like an entrance foyer.
Like the other room, this is also extremely damp.
EndText
  );
  set( "exits", ([
    "west" : PLANE+"damproom.c",
    "east" : PLANE+"elemchamber.c",
  ]) );
  set( "item_desc", ([
  ]) );
  create_door("east","west","A damp, wooden door","locked","elemkey",30);
  ::create();
  reset();
}
