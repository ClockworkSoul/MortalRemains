#include <mudlib.h>
#include "/d/Dark/High/high.h"

inherit ROOM;

void create()
{
  seteuid(geteuid());
  set("author","highlander");
  set( "light", 1 );
  set_outside();
  set("short","A boring room");
  set( "long", @EndText
Zuljin Street, 2 east of COT.
house to the north, house to the south.
EndText
  );
  set( "exits", ([
     "north":HIGHRM"/house3.c",
     "south":HIGHRM"/house5.c",
     "west":HIGHRM"/ze1.c",
     "east":HIGHRM"/ze3.c",
    ]) );
     set("item_desc", ([
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
