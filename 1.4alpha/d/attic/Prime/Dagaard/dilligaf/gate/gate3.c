#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "guard" : MON+"guard1.c" ]) );
  reset();
  set( "light", 1 );
  set("short" , "At the city gates");
  set( "long" , @EndText
  You are standing at the gates of the city. There is a path leading out
  into some fields to the north, and south into the city. The gate is
  well used, but is not the main one.

EndText
  );
  set( "exits", ([
    "north" : FIELDS+"field1.c",
    "south" : STREET+"street16.c",
  ]) );
  set("item_desc" , ([
    "gate" : "You stand before a huge gate, though not the main gate\n"+
    "it is still very impressive.\n",
  ]));
}
