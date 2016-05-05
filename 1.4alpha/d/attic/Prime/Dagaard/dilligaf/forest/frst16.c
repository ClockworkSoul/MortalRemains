#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "mugger" : MON+"mugger.c" ]) );
  reset();
  set( "light", 1 );
  set( "short" , "A forest path");
  set( "long" , @EndText
  You were warned to stay on the path, and now you're lost. Good luck
  finding your way back to the path.

          There are no obvious exits.

EndText
  );
  set( "exits", ([
    "north" : FOREST+"frst10.c",
    "south" : FOREST+"frst23.c",
    "east" : FOREST+"frst17.c",
    "west" : FOREST+"frst15.c",
  ]) );
  set("exit_suppress" , 1);
  set("item_desc" , ([
    "forest" : "There seems to be a very forboading edge to this place.\n",
    "path" : "You stepped off it, and now its gone.\n",
    "bushes" : "Bushes.\n",
  ]));
reset();
}
