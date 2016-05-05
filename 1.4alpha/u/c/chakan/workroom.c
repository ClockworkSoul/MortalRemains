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
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
Chakan's Workroom is obviously the home of a rampant kobold
as rags and random broken weapons and armor have been collected
and strewn about.  A series of different colored glass jars sit
in the northeast corner of the room, filled with a random 
assortment of rats, animal parts, insects (dead and partially-
alive).  Only a kobold could get any work done here.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
	"north"  :  "/u/c/chakan/edge/square/r1.c"
  ]) );

}
