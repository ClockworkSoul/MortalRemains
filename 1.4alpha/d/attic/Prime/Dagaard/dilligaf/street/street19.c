#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Crumple Street" );
  set( "long" , @EndText
  You stand upon Crumple street. People are moving all around you,
  off to the south you can see a small sign.

EndText
  );
  set( "exits", ([
    "west" : STREET+"street18.c",
    "east" : STREET+"street20.c",
    "south" : SHOPS+"shop7.c",
  ]) );
  set("item_desc" , ([
    "sign" : "Killian's Shop of Shops\n",
    "people" : "People.\n",
  ]));
}
