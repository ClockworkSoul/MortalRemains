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
As you enter this room, the most striking thing that 
is here is  the large chest in the center of the room,
you think, if you could find the key to it, you'd be 
rewarded with many things. The only other features
you need know about is the door leading back to the 
south, and the other to the east.
EndText
);
    set( "exits", ([
"east" : "room3.c",
"south" : "room1.c",
    ]) );
    set( "item_desc", ([

]) );

}


