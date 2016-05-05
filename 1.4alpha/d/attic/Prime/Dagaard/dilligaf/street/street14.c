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
  You stand upon Henderson Street. Far to the south you can see the
  gates of the city looming in the distance.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street13.c",
    "south" : STREET+"street15.c",
  ]) );
  set("item_desc" , ([
    "gate" : "You can't see it too well from here.\n",
  ]));
}
