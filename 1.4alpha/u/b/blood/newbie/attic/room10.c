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
Utter blackness is your only company in this room.
Black stone walls, black floor and ceiling, and black eyes.
Black eyes? What the hell is that?
Welcome to your doom!   Hahahahaha....................
Oh wait, wrong mortal. Be gone, you..
I do not have time for one as small as yourself!
Come back later when your strongest blow could even get 
passed my first shield. Better run then, eh?
EndText
);
    set( "exits", ([
"west" : "room8.c",
    ]) );
    set( "item_desc", ([

]) );

}


