#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "ghost" : MON+"ghost.c"]) );
  reset();
  set( "light", 1 );
  set("short" , "A graveyard");
  set( "long" , @EndText
  You have stumbled into the Dagaard cemetary. There are tombstones
  everywhere and you wonder exactly how many people are buried here.
  There is a path that leads through the tombstones and off to the
  south you can see the beginings of a building.

EndText
  );
  set( "exits", ([
    "north" : FOREST+"frst1.c",
    "south" : CEMETARY+"cem2.c",
    "west" : CEMETARY+"cem5.c",
  ]) );
  set("item_desc" , ([
    "building" : "You can't see it very well from here.\n",
    "path" : "A small dirt path that leads through the graveyard.\n",
    "tombstones" : "You can see different tombstones.\n",
  ]));
reset();
}
