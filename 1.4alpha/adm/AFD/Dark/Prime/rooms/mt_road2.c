#include "../Prime.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  seteuid(getuid());  // need this line if your gonna clone anything.
  set( "light", 1 );
  set ("short", "On a rocky mountain road");
  set( "long", @EndText
The forest, though still very thick has begun to thin out a bit.
The heat your surroundings is compounded with the increasingly
unbreatheable air.  Sweat exudes from your every poor.  You come
to the conclusion that the forest surrounding you must be magical
in nature to survive such a harsh climate.  The road is quite steep
at this point, making further progression to the north very difficult.
It appears there may be a structure to the north.
EndText
  );
  set ("author", "cyanide/waxer");
   set( "exits", ([
    "north" : D_PRIMER+"/mt_road3.c",
    "southeast" : D_PRIMER+"/mt_road1.c",
  ]) );
  ::create(); // this also resets the room! :)
  set ("item_desc", ([
   ]) );
}
