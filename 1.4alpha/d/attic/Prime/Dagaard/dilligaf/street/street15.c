#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Henderson Street");
  set( "long" , @EndText
  You stand upon Henderson Street. Off to the south looms the main
  gate of the city, arround it you can spot some of the guards.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street14.c",
    "south" : GATE+"gate2.c",
  ]) );
  set("item_desc" , ([
    "gate" : "This immense gate looms up into the sky.\n",
    "guard" : "You can't see them very well from here.\n",
    "guards" : "You can't see them very well from here.\n",
  ]));
}
