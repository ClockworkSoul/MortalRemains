#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Trainor Street");
  set( "long" , @EndText
  You stand upon Trainor Street. To the north you can hear music. There
  are lots of people milling about to the south.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street11.c",
    "south" : STREET+"street3.c",
  ]) );
  set("item_desc" , ([
    "people" : "People.\n",
  ]));
}
