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
Zuljin Street, 4 west of COT.
Also the edge of town.
EndText
  );
  set( "exits", ([
     "east":HIGHRM"/zw3.c",
    ]) );
     set("item_desc", ([
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
