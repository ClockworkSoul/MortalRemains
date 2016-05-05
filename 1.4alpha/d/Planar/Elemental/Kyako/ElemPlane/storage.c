/*
// The pirate's storage room.
*/

#include <mudlib.h>
#include "plane.h"

inherit ROOM;

void create()
{
  ::create();
   seteuid(getuid());
   set( "light", 1 );
   set("short","The pirate's storage room");
   set( "long", @EndText
You are in the pirate's storage room.
There are wooden boxes scattered everywhere.
It's strange, everything here is considerably damp.
EndText
  );
  set( "exits", ([
    "west" : PLANE+"barracks.c",
    "east" : PLANE+"ship.c",
    "down" : PLANE+"damproom.c",
  ]) );
  set( "item_desc", ([
    "boxes" : "Just some boxes.\n",
  ]) );
}

void init() {
  add_action("search", "search");
}

int search (string str) {
  object mon;
  if (str != "boxes") {
    write("Search what?\n");
    return 0;
  } else {
    write("A ferocious rat jumps out from behind the boxes!\n");
    mon = clone_object(PLANE+"monsters/f-rat.c");
    mon -> move(this_object());
    mon -> kill_ob(TP);
    return 1;
  }
}
