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
    It continues west,east, or south.

EndText
  );
  set( "exits", ([
    "west" : FOREST+"frst9.c",
    "east" : FOREST+"frst11.c",
    "south" : FOREST+"frst16.c",
    "southeast" : FOREST+"frst17.c",
    "southwest" : FOREST+"frst15.c",
  ]) );
  set("item_desc" , ([
    "trees" : "Large trees.\n",
    "bushes" : "Bushes.\n",
    "path" : "You wonder if you should stay on it.\n",
  ]));
}
