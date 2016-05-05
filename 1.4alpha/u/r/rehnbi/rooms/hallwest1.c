#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
set( "light", 10);
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
"east" : "/u/r/rehnbi/rooms/fltcastl1.c",
  ]) );
  set("item_desc", ([
"windows" : @endwind
These windows let in enormous amounts of light because they are
trapped between dimensions and the portal
is emmitting energy directly into the room.
endwind
 ]) );
}


