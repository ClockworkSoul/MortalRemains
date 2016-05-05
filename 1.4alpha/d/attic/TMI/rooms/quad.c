// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set( "short", "The famous Quad" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is the temporary Wizard Hall...
This is where you start, but you'll probably spend more time
in the Bug Board Room to the east...
EndText
  );
  set( "exits", ([
    "sigil" : "/d/Outer/Sigil/mainst1.c",
   "down" : "/d/Fooland/hall",
 "east" : "/d/TMI/rooms/bugroom",
    "void"  : VOID,
  ]) );

call_other("/d/TMI/boards/generalboard","dsfjkdgfjksf");
reset();
}
