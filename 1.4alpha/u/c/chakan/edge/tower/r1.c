#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
set( "short", "Tower room" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
Generic room.
EndText
  );
  set( "exits", ([
	"north"  :  "/u/c/chakan/edge/square/r1.c"
  ]) );
}
