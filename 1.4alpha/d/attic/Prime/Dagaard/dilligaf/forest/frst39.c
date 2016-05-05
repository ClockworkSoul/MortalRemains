#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set("short" , "A small path just outside the forest");
  set( "long" , @EndText
  Lots of trees line the path, the sound of birds chirping and singing
  is lulling you into a coma. However further to the south...the sound
  starts to die out.

EndText
  );
  set( "exits", ([
    "east" : FOREST+"frst38.c",
    "south" : FOREST+"frst40.c",
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
