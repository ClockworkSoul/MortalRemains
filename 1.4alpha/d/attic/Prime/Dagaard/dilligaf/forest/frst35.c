#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Forest Begining");
  set( "long" , @EndText
  You stand at the begining of a huge forest. There is a path leading
  into the trees and surrounding the path are some very large bushes.
  There is a small trail that leads off to the south while the path
  seems to continue south, north, and west.

EndText
  );
  set( "exits", ([
    "west" : FOREST+"frst34.c",
    "north" : PATH+"path9.c",
    "south" : FOREST+"frst36.c",
  ]) );
  set("item_desc" , ([
    "trees" : "Large trees.\n",
    "bushes" : "You see a small sign nestled in them.\n",
    "path" : "You wonder if you should stay on it.\n",
    "trail" : "It seems to go off to the south.\n",
    "sign" : "Stay on the path.\n",
  ]));
}
