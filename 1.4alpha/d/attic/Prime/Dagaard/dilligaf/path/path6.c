#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "gypsy" : MON+"gypsy.c" ]) );
  reset();
  set( "light", 1 );
  set("short" , "A lightly graveled path");
  set( "long" , @EndText
  You are walking along a lightly graveled path. Small stones litter the ground and
  you wonder how frequented this trail is to have such a mess ensue. Far off to the 
  west, you can just make the outline of a huge city...maybe thats where everyone
  is headed.

EndText
  );
  set( "exits", ([
    "north" : PATH+"path5.c",
    "south" : PATH+"path7.c",
  ]) );
  set("item_desc" , ([
    "stones" : "And lots of them, all over the path.\n",
    "path" : "A dirt path that leads away from the city.\n",
    "city" : "You can't make out any details from this distance.\n",
  ]));
reset();
}
