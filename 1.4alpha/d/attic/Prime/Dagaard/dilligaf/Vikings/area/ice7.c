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
  set("short" , "A path through the Viking village");
  set( "long" , @EndText
  You continue down the path. Off to the north west you can hear shouts
  and lots of noise coming from a large building in that direction.
  The houses here seem to be all the same, four walls, three windows,
  and a door.

EndText
  );
  set( "exits", ([
    "south" : ICE+"ice8.c",
    "north" : ICE+"ice6.c",
  ]) );
  set("item_desc" , ([
  ]));
reset();
}
