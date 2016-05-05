#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "Some fields");
  set( "long" , @EndText
  This is the very begining of a large field. All in here seems to be
  small animals and other things surrying about...just waiting for
  you to slay them. The way back in is to the city is south.

EndText
  );
  set( "exits", ([
    "north" : FIELDS+"field4.c",
    "south" : GATE+"gate3.c",
  ]) );
  set("item_desc" , ([
    "building" : "You can't see it very well from here.\n",
    "path" : "A small dirt path that leads through the graveyard.\n",
    "tombstones" : "You can see different tombstones.\n",
  ]));
reset();
}
