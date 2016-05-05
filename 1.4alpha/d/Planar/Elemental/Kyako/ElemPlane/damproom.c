/*
// A blank room, take it to make new rooms.
*/

#include <mudlib.h>
#include "plane.h"

inherit ROOM;

void create()
{
   seteuid(getuid());
   set( "light", 1 );
   set("short","An EXTREMELY wet room.");
   set( "long", @EndText
The other rooms in this ship were just damp,
but this room fits into the category of soaked.
Water is dripping everywhere, everything in the whole room
(including you) is soaked.
You are standing in two inches of water.
EndText
  );
  set( "exits", ([
    "up" : PLANE+"storage.c",
  ]) );
  set( "item_desc", ([
  ]) );
  ::create();
}

void init() {
  add_action("mueve", "search");
}

int mueve() {
  write("You find a small groove on the east wall, under the water.\n");
  write("You pull, and a secret passage opens up.\n");
  write("You go through it and close the door behind you.\n");
  write("----------------------------\n");
  say(TPN+" finds a secret passage and steps through it.\n");
  TP -> move_player(PLANE+"entfoyer.c");
  return 1;
}
