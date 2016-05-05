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
  You stand upon Henderson Street. There is slightly less traffic
  here as the people tend to stay on the main road. To the south
  is the Center of Towne.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street8.c",
    "south" : STREET+"street6.c",
  ]) );
  set("item_desc" , ([
    "center" : "The Center of Towne is off to the south.\n",
    "center of towne" : "The Center of Towne is off to the south.\n",
    "people" : "People.\n",
  ]));
}
