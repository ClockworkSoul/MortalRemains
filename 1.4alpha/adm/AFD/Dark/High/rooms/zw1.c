#include <mudlib.h>
#include "/d/Dark/High/high.h"

inherit ROOM;

void create()
{
  seteuid(geteuid());
  set( "light", 1 );
  set("short","A boring room");
  set( "long", @EndText
Zuljin street, west of COT.
EndText
  );
  set( "exits", ([
    "east":HIGHRM"/town_square.c",
     "west":HIGHRM"/zw2.c",
    ]) );
     set("item_desc", ([
       ]) );
  ::create(); // this also resets the room! :)
}
