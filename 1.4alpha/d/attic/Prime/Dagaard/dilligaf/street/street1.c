#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set( "short" , "Claddagh Street");
  set( "long" , @EndText
  You stand upon Claddagh Street. The well kept cobblestones tell you
  that the city before you is a rich one. Off to the south you can see
  the beginings of a forest. There are a few people milling about
  the streets, each going their own ways.

EndText
  );
  set( "exits", ([
    "south" : FOREST+"frst1.c",
    "east" : STREET+"street2.c",
  ]) );
  set("item_desc" , ([
    "cobblestones" : "Hand laid, well placed cobblestones.\n",
    "cobblestone" :  "Hand laid, well placed cobblestones.\n",
    "people" : "Random people, going every which way.\n",
    "forest" : "Lush trees and a large expanse of green is all you\n"+
               "can see to the south.\n",
    "city" : "Duh. The city you are about to enter.\n",
  ]));
  call_other("/d/Prime/Dagaard/dilligaf/obj/board.c" , "foo");
}
