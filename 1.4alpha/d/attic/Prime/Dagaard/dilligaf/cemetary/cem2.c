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
  set("short" , "A graveyard");
  set( "long" , @EndText
  You have stumbled into the Dagaard cemetary. There are tombstones
  everywhere and you wonder exactly how many people are buried here.
  There is a path that leads through the tombstones and off to the
  south you can begin to make out details of the building.

EndText
  );
  set( "exits", ([
    "north" : CEMETARY+"cem1.c",
    "south" : CEMETARY+"cem3.c",
    "west" : CEMETARY+"cem6.c",
  ]) );
  set("item_desc" , ([
    "building" : "You begin to see the makings of a large building.\n",
    "path" : "A small dirt path that leads through the graveyard.\n",
    "tombstones" : "You can see different tombstones.\n",
  ]));
reset();
}
