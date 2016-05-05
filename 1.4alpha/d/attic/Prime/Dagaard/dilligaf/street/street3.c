#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set ( "short" , "Intersection of Claddagh and Trainor");
  set( "long" , @EndText
  You are standing at the intersection of Claddagh and Trainor. The
  street is full of people fumbling around trying to escape the 
  rush of the crowd.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street10.c",
    "east" : STREET+"street4.c",
    "southwest" : STREET+"street2.c",
  ]) );
  set("item_desc" , ([
    "people" : "People.\n",
    "crowd" : "Lots of people.\n",
  ]));
}
