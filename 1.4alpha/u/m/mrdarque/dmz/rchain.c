#include <config.h>
#include <mudlib.h>
#include "/u/m/mrdarque/mrd.h",

inherit PUB;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "The Raging Chainsaw" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
The Raging Chainsaw a place for cheap drink and cheap action.
Any thing a person could ask for is here drugs,women,money
and even some professional work. The front of the Bar has the
bar its self with a few booth to sit in; while the back has the
combat pit for enjoyment of the blood thirsty patrons.
To the west is the stock room behind the bar and to the east is the 
managers office.

EndText
    );
    set( "exits", ([
"west" : "/u/m/mrdarque/dmz/stock.c",
"east" : "/u/m/mrdarque/dmz/office.c",
    ]) );
}
