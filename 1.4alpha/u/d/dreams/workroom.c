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

inherit PRIVATE_ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
set("author", "dreams");
  set( "light", 1 );
set("short", "Dreams' Magic Lab");
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
set( "long", @EndText
This is Dreams' Magic Lab, there is a desk at the center of the room
and papers all over the floor. Please be quiet, someone here is working.
Please take a sit and feel at home, Dreams will be glad to talk to you
in a momment.
EndText
  );
  set( "exits", ([
 "start" : START,
    "void"  : VOID,
  "portal" : "/u/d/dreams/rooms/hill.c",
"door" : "/u/r/ragevortex/workroom.c",
  ]) );
}
