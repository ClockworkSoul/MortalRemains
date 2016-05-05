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
Clang! clang! clang!.....
Pain explodes through your head as you walk around this
room. Warriors from the passed linger here, mortal.
Long, shiny, and extremely well forged blades, 
armourments and other asorted battle equipment are well 
organized through out this room. Each warrior who has 
equipment here, died in this room.
Formerly at a gravesite aparently the mage took a liking to
these noble sacrifices and transfered it, and all the contents
of the graves here. They are again preserved with unknown 
magics. You can hear the glory of each battle, individually 
and yet, as you stand here, they all seem to mingle into a 
story of triumph and grace. Battles fought for the needy, 
battles fought for honor. And your puny mortal self, dares 
to enter this? Heh, you are lame, aren't ya?
Some day, perhaps you will be among these.
EndText
);
    set( "exits", ([
"up" : "room7.c",
"southwest" : "room9.c",
"east" : "room10.c",
    ]) );
    set( "item_desc", ([

]) );

}


