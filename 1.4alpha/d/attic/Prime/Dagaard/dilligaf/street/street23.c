#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
inherit DOORS;


void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Claddagh Street");
  set( "long" , @EndText
  You are standing on Claddagh Street. There is a small sign to the
  north above the pub.

EndText
  );
  set( "exits", ([
    "north" : PUBS+"pub4.c",
    "west" : STREET+"street22.c",
  ]) );
  set("item_desc" , ([
    "sign" : "Mickey's Place\n",
    "dark" : "Umm. You can't see into the dark.\n",
  ]));
}
