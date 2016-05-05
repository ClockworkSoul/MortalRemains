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
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is the dwelling of Draconis, the Dragon Highlord of Krynn.
You notice that there is not a lot of clutter in the room since
it is very rare that Draconis is here. He spends most of his time
on Krynn attending to various duties. He does however, not take 
kindly to unwanted guests. For your sake, I hope that you were 
invited here because if not I would leave right now.
EndText
  );
  set( "exits", ([
"start"  :  "/d/Ancients/rooms/wizrm.c",
    "void"  : VOID,
    "duegne" : "/d/Prime/Krynn/Duegne/gates1.c",
  ]) );
}
