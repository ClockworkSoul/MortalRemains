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
Zulzin Street, 2 west of COT.
Bar to North.
EndText
  );
  set( "exits", ([
     "north":HIGHRM"/pub.c",
     "east":HIGHRM"/zw1.c",
     "west":HIGHRM"/zw3.c",
    ]) );
     set("item_desc", ([
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
