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
  You stand upon Henderson Street. Far off to the south you can see
  a large mass of people standing at what looks to be the center
  of this towne. 

EndText
  );
  set( "exits", ([
    "east" : STREET+"street9.c",
    "south" : STREET+"street7.c",
  ]) );
  set("item_desc" , ([
    "people" : "A few people milling about.\n",
    "center" : "You can't really see it well from here.\n",
    "center of towne" : "You can't really see it well from here.\n",
  ]));
}
