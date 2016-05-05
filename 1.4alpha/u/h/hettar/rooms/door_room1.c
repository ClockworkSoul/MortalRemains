/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
  object key;

  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
A room with a door number 1.
EndText
  );
  set( "exits", ([
    "north" : "/doc/examples/rooms/door_room2.c",
  ]) );

   create_door ("north", "south", "An iron door with a narrow slit",
      "locked", "silver_key");

// Okay...  this other stuff below just puts the key here.
  key = clone_object("/obj/obj/silver_key.c");
  key->move(this_object());
}
