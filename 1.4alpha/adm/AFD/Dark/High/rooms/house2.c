#include <mudlib.h>
#include "/d/Dark/High/high.h"

inherit ROOM;

void create()
{
  seteuid(geteuid());
  set("author","highlander");
  set( "light", 1 );
  set("short","A boring room");
  set( "long", @EndText
Abandoned house.
EndText
  );
  set( "exits", ([
     "west":HIGHRM"/sn3.c",
    ]) );
     set("item_desc", ([
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
