#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Intersection of Trainor and Crumple");
  set( "long" , @EndText
  You stand at the intersection of Trainor and Crumple. To the east
  you can hear the faintest rumble of music, to the north you can
  see one of the many gates leading into the city.

EndText
  );
  set( "exits", ([
    "north" : GATE+"gate3.c",
    "east" : STREET+"street17.c",
    "south" : STREET+"street12.c",
  ]) );
  set("item_desc" , ([
    "gate" : "Its a large black gate. There are a few guards.\n",
    "guards" : "You can't see them very well from here.\n",
  ]));
}
