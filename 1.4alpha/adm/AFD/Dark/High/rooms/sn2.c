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
Sargeras Road, 2 north of COT.
EndText
  );
  set( "exits", ([
     "north":HIGHRM"/sn3.c",
     "south":HIGHRM"/sn1.c",
    ]) );
     set("item_desc", ([
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
