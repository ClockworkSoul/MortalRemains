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
When you enter this cavern you notice that it becomes 
very bright.  All of the shadow's that were following you
are now here with you in this room.  They have yo
surronded and are blocking the way out.  You also notice
taht the walls are made of mud, and there are pools of
blood on the floor.
EndText
    );
    set( "exits", ([
"west" : KYRIE+"kyrie4.c",
    ]) );
}
