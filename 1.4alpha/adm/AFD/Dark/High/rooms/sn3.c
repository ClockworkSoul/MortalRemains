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
Sargeras Road, 3 north of COT.
house to east, house to west.
EndText
  );
  set( "exits", ([
     "south":HIGHRM"/sn2.c",
     "west":HIGHRM"/house1.c",
     "east":HIGHRM"/house2.c",
    ]) );
     set("item_desc", ([
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
