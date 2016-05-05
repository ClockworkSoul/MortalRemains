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
  You are standing at the gates of the city. The path continues west
  into the city, and northeast. This gate seems to be well used, though
  it is not the main one.

EndText
  );
  set( "exits", ([
    "east" : PATH+"path1.c",
    "west" : STREET+"street9.c",
  ]) );
  set("item_desc" , ([
    "gate" : "You stand before a huge gate, though not the main gate\n"+
    "it is still very impressive.\n",
  ]));
}
