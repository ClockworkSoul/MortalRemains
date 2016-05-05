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
    set( "long", wrap(
	"You are in a train station. A few shady characters sit on long "+
	"benches and you feel them watching you although you can't "+
	"catch them at it. There is a ticket agent here with a barely "+
	"legible sign posted above him. "
      ) );
    set( "exits", ([
      "north" : SOPHIA+"herbgarden.c",
    ]) );
    set("objects", ([
      "shady character" : "/u/s/sophia/shadyguy.c",
    ]) );
    reset();
    set("item_desc", ([
      "benches" : "They look like any old church pews. \n",
    ]) );
}

void init() {
    add_action("buy_func", "buy");
}

int buy( string str ) {
    if (str!="ticket") {
	write("Buy what?\n");
	return 1;
    }

    return 1;
}

/* EOF */
