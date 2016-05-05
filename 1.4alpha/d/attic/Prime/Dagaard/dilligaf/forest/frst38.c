#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "A small path just outside the forest");
  set( "long" , @EndText
  You continue down the path, lots of trees, lots of bushes, and lots
  of green. The leaves blow slowly in the wind, and the chirp of song
  birds makes you sleepy.

EndText
  );
  set( "exits", ([
    "north" : FOREST+"frst37.c",
    "west" : FOREST+"frst39.c",
  ]) );
  set("item_desc" , ([
    "trees" : "You gaze up at the trees and see that they go all the\n"+
    "way up.\n",
    "leaves" : "Leafy things.\n",
    "birds" : "Birds.\n",
  ]));
}
