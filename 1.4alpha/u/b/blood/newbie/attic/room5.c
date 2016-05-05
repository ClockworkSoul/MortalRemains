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
Your feet get soaked from the water on the ground, in
this room. In fact, as you look around, you have to blink
a bit as your eyes can't believe what your mind is telling
them. Rainbows of every size float in the air. How they
are here, you have no idea, because no visible light can
be seen. Suddenly you are sucked away to a different
place. A being of truly godlike proportions stands before
you. You disturb the guards? Why?
The beauty of this place overwhelms you and you can not
speak or reply. Very well, the being says, you are only
mortal anyway. You may pass. Beware the creature that
you will need to battle, though.
EndText
);
    set( "exits", ([
"east" : "room4.c",
    ]) );
    set( "item_desc", ([

]) );

}


