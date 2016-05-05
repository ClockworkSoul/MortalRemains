#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set("short" , "A small path just outside the forest");
  set( "long" , @EndText
  You are standing on a small path just outside the forest. The birds
  are chirping and the sun is shining.

EndText
  );
  set( "exits", ([
    "north" : FOREST+"frst35.c",
    "south" : FOREST+"frst37.c",
  ]) );
  set("item_desc" , ([
    "forest" : "You can't see it very well from here.\n",
    "woods" : "You can't see it very well from here.\n",
    "birds" : "Birds.",
    "bird" : "Birds.",
  ]));
}
