/*
// The first room in mini-water elemental plane
*/

#include <mudlib.h>
#include "plane.h"

inherit ROOM;

void create()
{
   seteuid(getuid());
   set( "light", 1 );
   set("short", "Cave");
   set("objects", ([ "captkey" : PLANE+"obj/pirkeye.c" ]) );
   set( "long", @EndText
You teleport into another room of the cave.
Now you can get out of this miserable hell-hole.
Don't forget to take the items!
EndText
  );
  set( "exits", ([
    "up" : PLANE+"eastship.c",
  ]) );
  ::create();
}

void init() {
  add_action("upe", "go");
}

int upe(string str) {
  if (str == "up") {
    object ob1, ob2;
    ob1 = clone_object (PLANE+"obj/pirkeye");
    ob1 -> move (this_object());
    TP->move_player(PLANE+"eastship.c");
    return 1;
  }
  return 0;
}
