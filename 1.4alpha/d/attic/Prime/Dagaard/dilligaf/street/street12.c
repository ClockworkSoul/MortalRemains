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
  You stand upon Trainor Street. The cobble stones on this road are the
  smoothest that you have ever felt. They actually shine when you
  look at them. The building to the east seems to be shaking with
  the music that comes from inside it.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street16.c",
    "south" : STREET+"street11.c",
  ]) );
  set("item_desc" , ([
    "stones" : "Very smooth stones.\n",
    "cobble stones" : "Very smooth stones.\n",
    "building" : "You look at the building and realize that it is\n"+
                 "literally shaking with a pumping beat that comes\n"+
                  "from inside.\n",
  ]));
}
