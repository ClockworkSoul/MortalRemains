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
  set( "short", "Control Room" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
Cold metal walls cover this room, they are covered with electrodes and monitors
There's a working desk and a bed here. Also there's a fridge for munchies.
The room is filled with crude technology and scratches all over the walls
EndText
  );
  set( "exits", ([
    "start" : START,
"north" : "/u/r/ragevortex/garden.c",
    "void"  : VOID,
  ]) );
set("item_desc", ([
"bed" : " A nice comfy bed for the one who works here.\n",
"desk" : "This is ragevortex's desk, he works here.\n",
"fridge" : "this is ragevortex's munchie machine for long work days.\n",
]) );
}
