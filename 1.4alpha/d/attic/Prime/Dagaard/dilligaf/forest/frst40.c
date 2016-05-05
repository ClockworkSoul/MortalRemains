#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set("short" , "A darkened path");
  set( "long" , @EndText
  You have wandered into a darker part of the forest, the noise from
  the animals seems to have died out here and the light has as well.
  You hear strange noises coming from both the southeast and the 
  southwest...who knows what lays in those directions.

EndText
  );
  set( "exits", ([
    "north" : FOREST+"frst39.c",
    "southeast" : FOREST+"frst42.c",
    "southwest" : FOREST+"frst41.c",
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
