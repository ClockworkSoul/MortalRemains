inherit ROOM;

// VERY IMPORTANT!!
#include "sophia.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "short", "A train station" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", wrap(
	"You are in a train station. A few shady characters sit on long "+
	"benches and you feel them watching you although you can't catch them "+
	"at it.  There is a ticket agent here with a barely legible sign "+
	"posted above him."
      ) );
    set( "exits", ([
      "north" : SOPHIA+"herbgarden.c",
    ]) );
    set("item_desc", ([
      "sand" : "hot and black.\n",
    ]) );
}
