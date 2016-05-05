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

inherit PRIVATE_ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set("short","Shallar's Study");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set("c_long",@EndLong
You have entered into a large study which has a long desk, covered with papers.
There are some comfortable chairs placed around the room available for
friends of Shallar to crash in while coding or talking. There is a large
bearskin rug in the middle of the floor and directly in front of the
fireplace, which magically roars to life as the temperature drops.
EndLong
    );
    set( "exits", ([
      "start" : START,
"shya":"/u/s/shya/workroom.c",
      "void"  : VOID,
    ]) );
}
