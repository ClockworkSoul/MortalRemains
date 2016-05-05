#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Claddagh Street");
  set( "long" , @EndText
  You stand upon Claddagh Street. People are everywhere.

EndText
  );
  set( "exits", ([
    "east" : STREET+"street6.c",
    "west" : STREET+"street4.c",
  ]) );
  set("item_desc" , ([
    "people" : "People.\n",
  ]));
}
