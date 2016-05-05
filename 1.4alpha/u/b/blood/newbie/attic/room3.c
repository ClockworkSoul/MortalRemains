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
This room gives you a feeling of warmth as you enter it.
Couches, beds, tables and chairs dominate this huge room
as well as a large fireplace with an incredibly hot fire 
blazing in it.  Along the eastern wall is another one of 
those blasted mirrors. You wonder if this mage was cute?
EndText
);
    set( "exits", ([
"west" : "room2.c",
"north" : "room4.c",
    ]) );
    set( "item_desc", ([

]) );

}


