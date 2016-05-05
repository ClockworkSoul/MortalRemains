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
  seteuid( 0 );
  set( "light", 1 );
set("short", "The mystical room of Zykor");
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
Stranger things you will not see after you have laid eyes upon
this room. Small furry creatures scatter about the floor and a
purple haze can be seen coming from the closet in the southern
corner of the room. Large light sources hang from the ceiling,
which seems to be quite has as you cannot see it. The northern
wall houses a small pentogram-shaped window, and out it you can
see the fires of Hell, singing the outside of the workroom. Atop
the large oak desk which sits by the window, are an array of toys
that are used to do their masters dirty work. You notice a rather
large hideaway bed that fits snugly in the wall with even larger
pillows lying on the floor where the bed would fold out. A warm
breeze is coming from a portal-like window facing outside.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
    "hall" : "/d/Ancients/rooms/wizrm.c",
    "enter" : "/u/z/zykor/realms.c",
  ]) );
}
