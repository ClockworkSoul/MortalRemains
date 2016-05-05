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
  You are standing on Claddagh Street. People everywhere are rushing
  to get to where they have to go. You can see two signs here.

EndText
  );
  set( "exits", ([
    "north" : SHOPS+"shop4.c",
    "south" : SHOPS+"shop1.c",
    "east" : STREET+"street5.c",
    "west" : STREET+"street3.c",
  ]) );
  set("item_desc" , ([
    "sign" : "Sign 1 or 2?\n",
    "signs" : "Sign 1 or 2?\n",
    "sign 1" : "'Donnie's House of Sex Toys' is above the north door.\n",
    "sign 2" : "'Hookers R Us' is above the south door.\n",
    "people" : "People.",
  ]));
}
