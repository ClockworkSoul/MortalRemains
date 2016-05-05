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
  you wonder how frequented this trail is to have such a mess ensue. Off to the west
  you can make out the beginings of a city whose gates loom up into the horizon.

EndText
  );
  set( "exits", ([
    "west" : PATH+"path1.c",
    "southeast" : PATH+"path3.c",
  ]) );
  set("item_desc" , ([
    "stones" : "And lots of them, all over the path.\n",
    "path" : "A dirt path that leads away from the city.\n",
    "city" : "You can't quite see it clearly from here, but its Dagaard.\n",
  ]));
reset();
}
