#include <config.h>
#include <mudlib.h>
#include "insane.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set("author","shallar");
  set("short","restaurant");
  set( "long", @EndText
This is the main room in a restaurant. Waiters go sliding around the
floor trying to make sure that orders are finished. You may want to
order some lemonade to enjoy during this lovely weather.
EndText
  );
  set("smell", "It smells like a fresh day in the country, with a touch of \n"
               "chalk dust floating in the air.\n");
set("item_desc", ([
"floor":"This floor doesn't look slippery, but the waiters have a hard time maintaining their footing! \n",
"room":"This room has chairs and tables for patrons to be waited at. \n",
"tables":"Nice rought iron tables. A perfect complement to your surroundings. \n",
"chairs":"Chairs made out of rought iron with fluffy cushions on them. \n",
]));
  set("listen", "You can hear the sounds of a calliope farther down the passage.\n");
  set( "exits", ([ "northwest" : INS_ROOM+"cave8.c" ]) );
}



void reset()
{
  seteuid( getuid() );
  ::reset();
  if (!present("penguin", this_object())) {
    object peng;
    object peng2;

    peng = clone_object(INS_MON + "peng1.c");
    if (peng)
      peng -> move(TO);
    peng2 = clone_object(INS_MON + "peng2.c");
    if (peng2)
      peng2-> move (TO);
  }
}
