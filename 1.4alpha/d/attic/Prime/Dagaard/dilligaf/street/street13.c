#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Henderson Street");
  set( "long" , @EndText
  You stand upon Henderson Street. Off to the north you can see the 
  Center of Towne, to the west there is a lifeless alley that doesn't
  look like it would be the safest place to go exploring. Far off to
  the south you can see the high tiers of one of the gates.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street6.c",
    "west" : STREET+"alley1.c",
    "south" : STREET+"street14.c",
  ]) );
  set("item_desc" , ([
    "center of towne" : "You can't really see it well from here.\n",
    "alley" : "I wouldn't want to go down there.\n",
    "tier" : "Part of the gate that you can see above the buildings.\n",
    "tiers" : "Part of the gate that you can see above the buildings.\n",
    "gate" : "One of the gates leading into the city.\n",
  ]));
}
