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
  To the north is the main gates of Dagaard, it is a huge monolith
  with giant tiers arcing up into the sky.
    The path continues east, west, or south.

EndText
  );
  set( "exits", ([
    "southeast" : FOREST+"frst16.c",
    "south" : FOREST+"frst15.c",
    "southwest" : FOREST+"frst14.c",
    "west" : FOREST+"frst8.c",
    "east" : FOREST+"frst10.c",
    "north" : GATE+"gate2.c",
  ]) );
  set("item_desc" , ([
    "trees" : "Large trees.\n",
    "bushes" : "Bushes.\n",
    "path" : "You wonder if you should stay on it.\n",
    "gate" : "It towers high above the trees.\n",
    "tiers" : "They shoot up to the sky like stone fingers.\n",
    "tier" : "They shoot up to the sky like stone fingers.\n",
  ]));
}
