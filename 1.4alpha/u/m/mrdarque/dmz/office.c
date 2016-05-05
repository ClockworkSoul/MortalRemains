#include <config.h>
#include <mudlib.h>
#include "/u/m/mrdarque/mrd.h",

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "Managers Office" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
The manager's office is in shambles. Papers and documents are in every
inch of the office. The only semi-clear spot is the desk where work is
done. The room is small, only making the mess inside feel only worse.
the north eastern corner of the room has a file cabinet with a few
notes on the side. The west goes back to the Raging Chainsaw.

EndText
    );
    set( "exits", ([
"west" : "/u/m/mrdarque/dmz/rchain.c",
    ]) );
}
