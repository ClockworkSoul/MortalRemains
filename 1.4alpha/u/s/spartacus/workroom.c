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
  set( "short", "Sparky's tower" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is Spartacus's Tower, not to be confused with that damned Dark
Tower that Roland is searching for.  If you happen to see him or the Jesus 
Man, send them away, please.
You feel quite righteous in this place.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
}
