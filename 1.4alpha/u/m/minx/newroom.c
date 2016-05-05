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

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
seteuid(getuid());
  set( "light", 1 );
set("short", "High cliff above a waterfall")
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
   set("long", @EndText
You have entered Minx' sanctuary.
You find yourself in a circular room, two thickly carpeted tiers 
follow the perimeter of the room and lead down to the well area
in the center. Stepping down you notice that the floor is padded,
as for sleeping and covered in the softest fur imaginable. There
are many large throw pillows scattered about. High above you
is a domed ceiling and there are muted sconces, spaced at intervals 
along the walls, lighting the room. Hanging as a tapestry 
is a fine kashmir carpet, a gift from a friend.
Arched doorways lead out of the room and you notice an alcove to 
one side.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
    "alcove" : "/u/m/minx/alcove.c",
  ]) );
}
