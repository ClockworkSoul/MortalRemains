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
  south you can see some of the details of the building.

EndText
  );
  set( "exits", ([
    "north" : CEMETARY+"cem5.c",
    "south" : CEMETARY+"cem7.c",
    "east" : CEMETARY+"cem2.c",
  ]) );
  set("item_desc" , ([
    "building" : "It looks as if to be some sort of keep.",
    "path" : "A small dirt path that leads through the graveyard.\n",
    "tombstones" : "You can see different tombstones.\n",
    "keep" : "You can't see it very well from here.\n",
  ]));
reset();
}
