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
  seteuid( getuid() );
  set( "light", 1 );
set( "author", "sophia");
set( "short", "Sophia's kitchen" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
Wonderful smells overwhelm your senses as you look around
this amazing kitchen...you decide Sophia must really like cooking as
you consider asking for a piece of that pie on the table.
EndText );
  set( "exits", ([
"east" : "/u/s/sophia/playground.c",
"door" : "/u/s/sophia/herbgarden.c",
  ]) );
}
