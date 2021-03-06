/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of WEST and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set( "short", "the great room" );
set("item_desc", ([
"love" : "a very comfortable white leather love seat.\n",
"seat" : "a very comfortable white leather love seat.\n",
"stereo" : "A Kickin' Infinity Sound system.\n"
]) );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
You have entered the Great Room to Spooner the Great!!
His desk is very messy and it appears that he is very 
busy at this time.  You see here a very comfortable
Love seat and a very killer sound system.  So why 
don't you take a load off and listen to some tunes!!
EndText
  );
  set( "exits", ([
  ]) );
}
