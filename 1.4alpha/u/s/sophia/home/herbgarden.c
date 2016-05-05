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
set( "short", "The HERB Garden" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
A must for every serious cook..herbs grow here in what once
must have been a formal garden but the rosemary grows free now and
Sophia has long since lost control of the mint.
Square slate tiles give way to a meandering path.
EndText );
  set( "exits", ([
"door" : "/u/s/sophia/kitchen.c",
"path" : "/u/s/sophia/meadow.c",
  ]) );
}
