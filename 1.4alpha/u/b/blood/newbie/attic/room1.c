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
You have entered the house of the famed mage prectorian.
This room is supported by large pillars formed from a
yellowish stone that looks as if it was polished many
many times by dedicated hands.
A tall mirror stands to the left of the north exit,
giving you a  look at your ugly mug.
A fountain also stands tall in the center. The fountain has
the form of a large dragon with water  spouting from
its large open mouth, falling down inbetween the splayed
claws of the huge and horribly beautiful beast.
This is the main entrance. If the rest of the house is
as nice  as this, this mage must have been quite wealthy.
EndText
);
    set( "exits", ([
"north" : "room2.c",
"south" : "?",
    ]) );
    set( "item_desc", ([

]) );

}


