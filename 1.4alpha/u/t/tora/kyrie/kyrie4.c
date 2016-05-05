/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.

#include "kyrie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "kyrie forest" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
You enter a very clean and very comfortable cave, you 
notice that this mainroom of the cave is very clean.  You 
see a cavern off to the west and a similar one to the east.
You also see that the cave continues to the North.
EndText
    );
    set( "exits", ([
      "south" : KYRIE+"kyrie3.c",
"east" : KYRIE+"kyrie6.c",
"west" : KYRIE+"kyrie5.c",
"north" : KYRIE+"kyrie7.c",
    ]) );
}
