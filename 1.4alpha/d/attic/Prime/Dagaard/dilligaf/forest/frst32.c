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
  You are walking along a forest path. Nothing really amusing here,
  just a bunch of trees and a few bushes line the path. 
    The path goes back to the north but in no other direction.

EndText
  );
  set( "exits", ([
    "south" : FOREST+"frst43.c",
    "north" : FOREST+"frst28.c",
    "east" : FOREST+"frst33.c",
    "west" : FOREST+"frst31.c",
    "northeast" : FOREST+"frst29.c",
    "northwest" : FOREST+"frst27.c",
  ]) );
  set("item_desc" , ([
    "trees" : "Large trees.\n",
    "bushes" : "Bushes.\n",
    "path" : "You wonder if you should stay on it.\n",
  ]));
}
