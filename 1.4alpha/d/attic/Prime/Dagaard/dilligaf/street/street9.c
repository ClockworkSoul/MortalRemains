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
  You stand upon Henderson Street. Off to the east you can see a gate
  that is one of the many entrances into Dagaard. There are a few
  guards, but mostly they don't seem to be paying you any attention.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street21.c",
    "east" : GATE+"gate1.c",
    "west" : STREET+"street8.c",
  ]) );
  set("item_desc" , ([
    "guard" : "You can't make them out too well from here.\n",
    "guards" : "You can't make them out too well from here.\n",
    "gate" : "One of the many gates leading into the city.\n",
  ]));
}
