#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "traveler" : MON+"traveler.c"]) );
  reset();
  set( "light", 1 );
  set("short" , "A lightly graveled path");
  set( "long" , @EndText
  You are walking along a lightly graveled path. Small stones litter the ground and
  you wonder how frequented this trail is to have such a mess ensue. Off to the northwest
  you begin to make out a city, while the path continues to the south.

EndText
  );
  set( "exits", ([
    "north" : PATH+"path3.c",
    "south" : PATH+"path5.c",
  ]) );
  set("item_desc" , ([
    "stones" : "And lots of them, all over the path.\n",
    "path" : "A dirt path that leads away from the city.\n",
    "city" : "You can't make out any details from this distance.\n",
  ]));
reset();
}
