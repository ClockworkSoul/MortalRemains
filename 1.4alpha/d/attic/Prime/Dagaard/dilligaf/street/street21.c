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
  You stand upon Henderson Street. Off to the south east you can see
  a gate.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street20.c",
    "south" : STREET+"street9.c",
  ]) );
  set("item_desc" , ([
    "gate" : "A large gate, there are some guards around it.\n",
    "guards" : "You can't see them all that well from here.\n",
  ]));
}
