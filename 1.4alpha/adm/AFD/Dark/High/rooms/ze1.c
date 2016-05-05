#include <mudlib.h>
#include "/d/Dark/High/high.h"

inherit ROOM;

void create()
{
  seteuid(geteuid());
  set( "light", 1 );
  set("short","A boring room");
  set_outside();
  set( "long", @EndText
Zulzin Street, 1 east of COT.
Pub to the north.
EndText
  );
  set( "exits", ([
     "north":HIGHRM"/shop.c",
     "west":HIGHRM"/town_square.c",
     "east":HIGHRM"/ze2.c",
    ]) );
     set("item_desc", ([
       ]) );
  ::create(); // this also resets the room! :)
}
