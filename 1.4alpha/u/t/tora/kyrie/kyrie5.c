/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.

#include "kyrie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "kyrie forest" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
Ass you entr this cavern you notice it doesn't seem as
clean as the other cavbern.  You notice that the mud that
make's up the walls is very soft.  There is a pile of fresh
bones in one of the corners of the cavern.
EndText
    );
    set( "exits", ([
"east" : KYRIE+"kyrie4.c",
    ]) );
}
