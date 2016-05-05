#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "The Kitchen" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
Here is Seb's kitchen.  There is absolutely nothing to eat in here.
  You could say that after one too many people crashing at his place
, that SEb just doesn't bother keeping anything around.  The lights are 
dimmed, and it's a cooler temp in here.  There's really nothing to do 
here.

EndText
    );
    set( "exits", ([
"south" : "/u/s/sebastian/livingroom.c",
    ]) );
}
