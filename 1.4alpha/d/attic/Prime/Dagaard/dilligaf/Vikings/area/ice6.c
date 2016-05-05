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
  set("short" , "A small intersection");
  set( "long" , @EndText
  You have come to an intersection in the road. Off to the west you can
  see a large building. Loud noises and alot of commotion seems to be
  comming from there. The main path also continues north and south.

EndText
  );
  set( "exits", ([
    "north" : ICE+"ice5.c",
    "south" : ICE+"ice7.c",
    "west" : ICE+"ice11.c",
  ]) );
  set("item_desc" , ([
    "building" : "As you look at the building, one of the windows smashes open and two very large men come flying out. They continue their brawl outside while inside the cheers from the crowd continue.\n",
    "path" : "It continues north and south, and intersects to the west.\n",
  ]));
reset();
}
