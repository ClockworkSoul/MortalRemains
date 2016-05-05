/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit DOORS;

inherit ROOM;



void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "Attic");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
As you enter the attic, the smells of dust and old wood
assault your nostrils. Crossbeams made of oak zigzag 
over your head to form a spell of protection that shields
the entire house from unknown magical forces. You also
notice that it is quite warm here.
EndText
    );
    set( "exits", ([
"east" : "attic2.c",
"down" : "room16.c",
    ]) );

create_door("down", "up", "A strong wooden door "+
"which forms another complex spell of magic within its "+
"framework.", "locked", "magic key", 25);

}


/* EOF */
