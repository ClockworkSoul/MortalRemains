#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
inherit DOORS;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "A path going the the village");
  set( "long" , @EndText
  You are wandering down the path through the village. Off to the west
  you can hear the sounds getting louder. As you look in that direction
  you can see a large building growing nearer as you walk.
EndText
  );
  set( "exits", ([
    "north" : ICE+"ice3.c",
    "south" : ICE+"ice6.c",
  ]) );
  set("item_desc" , ([
    "building" : "Off to the west you can see the begining of a large building. Loud noises and crashes seem to be coming from it.\n",
    "path" : "A path leading through the village.\n",
  ]));
reset();
}
