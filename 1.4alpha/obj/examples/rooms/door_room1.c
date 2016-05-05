/* Chronos rewrote this to show how his new door code works. :D */
#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
  object key;

  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short", "On the east side of a door.") ;
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
You stand on the east side of a door, in a room with no features.
EndText
  );
  // You need to define a valid exit before calling create_door()
  set( "exits", ([
   "west" : "/doc/examples/rooms/door_room2",
  ]) );

// create_door() arguments...
// "west"  -  First argument is the direction of the door.
// "east"  -  Second argument is the direction of the door in the 
//            connecting room.
// "A solid..." - Description for the door.
// "locked" - Door status.  Locked, Open, or Closed.  (lower case)
// "silver_key" - Key id.
// 23   - Strength required to "bash" the door down.  See "help bash"
  create_door("west", "east", "A solid iron door with a narrow slit.",
  "locked", "silver_key", 23) ;

// Okay...  this other stuff below just puts the key here.
  key = clone_object("/obj/obj/silver_key.c");
  key->move(this_object());
}
