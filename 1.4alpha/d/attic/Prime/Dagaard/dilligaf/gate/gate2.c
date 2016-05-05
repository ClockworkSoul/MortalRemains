#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "guard" : MON+"guard1.c" ]) );
  reset();
  set( "light", 1 );
  set( "short" , "The Main Gates" );
  set( "long" , @EndText
  You are standing just on the inside of the Main Gates of the City
  of Dagaard. There are people wandering in and out of the gates
  themselves, and the guards...though well armed...are seemingly not
  paying too much attention to them.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street15.c",
    "south" : FOREST+"frst9.c",
  ]) );
  set("item_desc" , ([
    "guard" : "Well armed, but not paying much attention to you.\n",
    "guards" : "Well armed, but not paying much attention to you.\n",
    "gate" : "\n"+
    "You stare at the massiveness of this gate. The HUGE doors on it\n"+
    "look as if they would keep a dragon at bay. Intricate carvings\n"+
    "outline the portcullis, and the stone tiers dwarf you as they\n"+
    "reach out for the sky.\n",
    "carvings" : "They look like runes for a ward.\n",
    "rune" : "You can't understand them.\n",
    "runes" : "You can't understand them.\n",
    "portcullis" : "A large wooden grate, used to keep people out.\n",
    "tiers" : "Stone fingers reaching up to the sky.\n",
    "tier" : "Stone fingers reaching up to the sky.\n",
  ]));
  reset();
}
