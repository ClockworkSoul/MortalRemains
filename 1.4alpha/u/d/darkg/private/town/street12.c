#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "Busy Bazzar");
  set("long", @ENDTEXT
This is the beggining of the towns trading market.
The street is crowded with people. There are many stands
that sell just about everything.  From the south
you can hear the loud banging from the smiths.
ENDTEXT
);
  set( "exits", ([
         "east" : AROOM+"armor.c",
         "west" : AROOM+"street11.c",
         "south" : AROOM+"weapshop.c",
         "north" : AROOM+"street19.c",
  ]) );
}
