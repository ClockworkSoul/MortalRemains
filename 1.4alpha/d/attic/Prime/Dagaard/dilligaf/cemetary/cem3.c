#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "skeleton" : MON+"skeleton.c"]) );
  reset();
  set( "light", 1 );
  set("short" , "A graveyard");
  set( "long" , @EndText
  You have stumbled into the Dagaard cemetary. There are tombstones
  everywhere and you wonder exactly how many people are buried here.
  There is a path that leads through the tombstones and off to the
  south the building starts to loom before you.

EndText
  );
  set( "exits", ([
    "north" : CEMETARY+"cem2.c",
    "south" : CEMETARY+"cem4.c",
    "west" : CEMETARY+"cem7.c",
  ]) );
  set("item_desc" , ([
    "building" : "You start to notice that the building is more of a castle, or a keep of some kind.\n",
    "keep" : "You can't make out the details.\n",
    "castle" : "You can't make out the details.\n",
    "path" : "A small dirt path that leads through the graveyard.\n",
    "tombstones" : "You can see different tombstones.\n",
  ]));
reset();
}
