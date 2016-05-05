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
  set( "light", 1 );
set( "short", "The Bedroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is the bed room of that poor bastard PanzerGiest or Dannar Ericson.
The romm is painted black with chains hanging down. The bed looks large
enough for two and it seems.uh..sturdy. The stero in the room looks
new and is ready for you to use. There is a heap of clothes in the 
corner ready to be worn tomorrow.
EndText
  );
  set( "exits", ([
"east" : "/u/p/panzergiest/workroom.c",
"south" : "/u/p/panzergiest/room/bathroom.c",
  ]) );
}
