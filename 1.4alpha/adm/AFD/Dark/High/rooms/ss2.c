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
Sargeras Road, 2 south of COT.
EndText
  );
  set( "exits", ([
     "north":HIGHRM"/ss1.c",
     "south":HIGHRM"/shrine1.c",
     "east":HIGHRM"/house6.c",
    ]) );
     set("item_desc", ([
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
