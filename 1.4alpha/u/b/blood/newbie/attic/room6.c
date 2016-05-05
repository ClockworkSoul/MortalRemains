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
set( "short", "House of Mage");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
Yow!!! Yow!!, my eyes! my eyes!.....
That is the only thing you can shout as you enter this
room. Bright balls of light fly around this room,
reflecting off the millions and millions of silver scrolls
that are stored in nitches in the wall. This must have
been mr.mages library. Only one with powers to shield 
the mind and body from the defenses of the scrolls
could even touch them, much less read them.
Oh, just to remind you, that isn't you, so don't even think
about it. However, if you could, the power within these
scrolls could be used to kill immortals, think about that.
EndText
);
    set( "exits", ([
"west" : "room2.c",
"south" : "room7.c",
    ]) );
    set( "item_desc", ([

]) );

}


