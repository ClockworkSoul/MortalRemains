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
set( "short", "The bathroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
The stark,cold bathroom has a small shower,a toilet and a counter to
fix yer self up.The counter has a mirror to see ya self and has tooth
brushes and toiletries all over the place.
EndText
  );
  set( "exits", ([
"north" : "/u/p/panzergiest/bedroom.c",
  ]) );
set("item_desc", ([
"toilet" : "aw man theres still a log in there.\n",
"toiletries" : "shaving cream,tooth paste,razor,brush,calone,.\n",
"mirror" : "ahhhhh what the hell is that! oh wait its me whew.\n",
"shower" : "damn that looks like it could only fit two people.\n",
]) );
}
