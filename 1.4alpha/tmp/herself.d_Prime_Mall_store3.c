#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Wild Pair");
    set("long", wrap(
	"Crazy shoes are on display here. Most are black "+
	"with chunky heals. An exotic pair of boots catch your eye. "
      ) );
    set("item_desc", ([
      "shoes" : "They're Craaaaazyyy! \n",
      "heals" : "Big and chunky. \n",
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'The Wild Pair'. \n",
      "crazy shoes" : "They're Craaaazyyyy!\n",
      "boots" : "They are red, with 7 inch heals. \n",
      "prices" : "The prices are a bit high, but not too bad. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set("listen" , "Some weird ass techno music is playing here. \n");
    set("objects" , ([
      "clerk" : MALL+"mons/clerk.c",
      "shopper" : MALL+"mons/shopper.c",
      "teen" : MALL+"mons/teeny.c",
    ]) );
    reset();
    set( "exits", ([
      "west" : MALL+"mall1.c",
    ]) );
}
