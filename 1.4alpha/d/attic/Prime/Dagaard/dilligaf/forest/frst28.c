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
    It continues either north or south.

EndText
  );
  set( "exits", ([
    "north" : FOREST+"frst22.c",
    "south" : FOREST+"frst32.c",
    "east" : FOREST+"frst29.c",
    "west" : FOREST+"frst27.c",
    "northeast" : FOREST+"frst23.c",
    "northwest" : FOREST+"frst21.c",
    "southeast" : FOREST+"frst29.c",
    "southwest" : FOREST+"frst27.c",
  ]) );
  set("item_desc" , ([
    "trees" : "Large trees.\n",
    "bushes" : "Bushes.\n",
    "path" : "You wonder if you should stay on it.\n",
  ]));
}
