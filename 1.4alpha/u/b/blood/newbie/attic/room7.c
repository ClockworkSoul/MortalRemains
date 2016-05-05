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
Wish for love, wish for life.
All this power, sharper then a knife.
Silver strands, performing commands,
Waiting here, and the masters fear.
Rising high, with glorious wings
Filling out, the call of the rings.
Mortal eyes, peer through dark
Asking for power, to perform the will, of some dark deed.
Shalow waters, granting passages on a string of fate.
Lines upon lines of silver strands, waiting and waiting, for
Those evil, commands.
EndText
);
    set( "exits", ([
"north" : "room6.c",
"down" : "room8.c",
    ]) );
    set( "item_desc", ([

]) );

}


