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
    set( "short", "A workroom" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
You are entering the forest of Kyrie, as you are walking along the
path you keep seeing a shadow that isn't yours following.  You
really feel uncomfortable here.  The forest is very dark and feels
haunted.  There is a little peaceful stream that flows here and it
seems to be the only thing with any brightness to it here.
EndText
    );
    set( "exits", ([
      "north" : KYRIE+"kyrie2.c",
    ]) );
}
