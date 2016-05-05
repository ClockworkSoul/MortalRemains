#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
set("short", "A Long East-West Marble Hallway");
set("objects", ([ "servant" :"/u/r/rehnbi/monsters/servant"]));
reset();
  set("long", @ENDTEXT
You've just entered a long hall with large
windows on either side.  The windows offer
incredible views down to the ground below on
both sides.  A white marble arched ceiling is over 
the whole length of the hall.  Running down the 
length of the ceiling, evenly spaced, are arched
windows letting in the afternoon sun.
ENDTEXT
);
  set( "exits", ([
"west" : "/u/r/rehnbi/rooms/fltcastl1.c",
  ]) );
  set("item_desc", ([
"windows" : "The windows offer a fantastic view to the left and right of the hallway.  The left side has a picturesque view of Kyrnn woods, and a pristine lake with a clear bluish waterfall running into it.  Meanwhile on the left is a view of a beach, with a calm ocean spraying the shore lazily with small waves.  A ship is docked at the ocean.  \n",
 ]) );
}


