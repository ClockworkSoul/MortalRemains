#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Claddagh Street");
  set( "long" , @EndText
  You stand upon Claddagh Street. The cobblestones here remind you
  of an exquisite painting you saw once, but the street was paved
  in gold...yet these are stones. Off to the southwest you can see
  the beginings of a forest.

EndText
  );
  set( "exits", ([
    "west" : STREET+"street1.c",
    "northeast" : STREET+"street3.c",
  ]) );
  set("item_desc" , ([
    "forest" : "You can't see it very well from here.\n",
    "stones" : "Rocks that were smoothed to line the street.\n",
  ]));
}
