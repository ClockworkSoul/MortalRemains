#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit PUB;

void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "mickey" : MON+"mickey.c" ]) );
  reset();
  set( "light", 1 );
  set("short" , "Mickey's Pub");
  set( "long" , @EndText
  You have made it into Mickey's pub, basically a non-descript little
  pub. The wooden floors creak as you enter, but the wooden bar shines
  and looks as if its polished enough to see your face in it.

  The commands here are: menu, buy <drink>, powerheal <drink>.

EndText
  );
  set( "exits", ([
    "south" : STREET+"street23.c",
  ]) );
  set("item_desc" , ([
    "bar" : "It is well polished and taken care of.\n",
    "floor" : "It is old and well used.\n",
  ]));
}
