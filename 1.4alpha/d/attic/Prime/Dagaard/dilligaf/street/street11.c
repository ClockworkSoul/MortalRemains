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
  You stand upon Trainor Street. The building to the east is shaking
  with music that comes from inside.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street12.c",
    "south" : STREET+"street10.c",
  ]) );
  set("item_desc" , ([
    "building" : "The building seems to be shaking.\n",
  ]));
}
