
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
#include "/u/d/dragoon/include/format.h"

inherit ROOM;

void create()
{
    ::create();
    // Inspiral fears Root euid.  94-08-18
    seteuid(getuid()) ;
    set( "light", 1 );
    set("short", "Yvan's Workroom");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", format(
	"This is a large hexagonal room, with very high ceilings. "
	"The northern wall consists of a large bookcase. "
	"Next to the bookcase, on the northwestern wall, is a richly colored tapestry. "
	"A large oaken table and chairs sits in the eastern half of the room. "
	"Several shimmering portals are set into the three southern walls. "
      )) ;
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
    ]) );

    set( "item_desc", ([
      "tapestry" : "A gargoyle guarding a shimmery doorway. It seems to be watching you.\n",
      "bookcase" : "Shelf after shelf of books containing the history of the world.\n",
      "table" : "A large, polished oaken table. There is a small rune in the southeast corner.\n",
      "rune" : "A complex pattern, forming a knot. It is worn, as if traced by many hands.\n",
    ])) ;
    call_other("/u/y/yvan/board.c", "foo") ;
}

void init()
{
    add_action("trace", "trace") ;
}

int trace(string str)
{
    if (str!= "rune" )
    {
	notify_fail("What do you want to trace?\n") ;
	return 0 ;
    }
    write ( format(
	"You trace the rune, and the world begins to blur before you. "
	"You feel as though your body is being ripped to shreds. "
	"The feeling subsides, and you realize that you are not where you began. "
      )) ;
    this_player()->move("/u/y/yvan/sanctum.c") ;
    return 1 ;
}
