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
Mystical Shrine, 3rd floor.
EndText
  );
  set( "exits", ([
     "down":HIGHRM"/shrine2.c",
    ]) );
     set("item_desc", ([
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
