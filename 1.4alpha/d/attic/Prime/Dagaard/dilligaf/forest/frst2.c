#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "A forest path");
  set( "long" , @EndText
  You have just entered the most lush forest that you have ever come
  across. The trees jut up out of the ground and soar up towards the
  sky. Green leaves wave slowly in the wind, and the chirp of crickets
  and the songs of birds make you sleepy.

EndText
  );
  set( "exits", ([
    "northwest" : FOREST+"frst1.c",
    "southeast" : FOREST+"frst4.c",
    "south" : FOREST+"frst3.c",
  ]) );
  set("item_desc" , ([
    "trees" : "You gaze up at the trees and see that they go all the\n"+
    "way up.\n",
    "ground" : "You examine the ground and notice something in the\n"+
    "bushes.\n",
    "bushes" : "You discover a small sign in the bushes.\n",
    "sign" : "Remember....don't stray from the path...\n",
    "leaves" : "Leafy things.\n",
    "birds" : "Birds.\n",
  ]));
}
