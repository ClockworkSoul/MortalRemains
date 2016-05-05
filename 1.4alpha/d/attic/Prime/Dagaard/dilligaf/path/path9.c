#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "A lightly graveled path");
  set( "long" , @EndText
  You are walking along a lightly graveled path. Small stones litter the ground and
  you wonder how frequented this trail is to have such a mess ensue. Just to the south
  west you can see a forest.

EndText
  );
  set( "exits", ([
    "north" : PATH+"path8.c",
    "south" : FOREST+"frst35.c",
  ]) );
  set("item_desc" , ([
    "stones" : "And lots of them, all over the path.\n",
    "path" : "A dirt path that leads away from the city.\n",
    "forest" : "You can make out trees, and other foresty things.\n",
  ]));
reset();
}
