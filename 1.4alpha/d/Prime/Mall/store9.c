#include "mall.h"

inherit BUYONLY_SHOP;

void create()
{
    ::create();
    seteuid( getuid() );
    stock = ([
    "tux.c" : 10,
    "ttux.c" : 6,
    "wtux.c" : 3,
    "wttux.c" : 1,
  ]);
    set("shopkeeper" , "joe");
    set("shop_dir", MALL+"inv/");
    set( "light", 1 );
    set("author", "Herself");
    set("objects" , (["joe" : MALL+"mons/joe.c"]) );
    reset();
    set("short" , "The Tux Shop");
    set("long", wrap(
	"So, you want to get married huh?  "+
	"Well you better look your best. This is the place "+
	"to pick up your snazzy tuxedo and all that "+
	"goes with it. The tailor waits in a room east of here "+
	"to get you all fit. When you purchase a tux, be specific, "+
	"<ie; 'white tux tails'> so you don't get the wrong one. "
      )+"Commands are: list, buy <item>\n");
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'The Tux Shop'. \n",
      "tux" : "There are many different styles. \n",
      "tuxedo" : "There are many different styles. \n",
      "prices" : "The prices are a bit high, but not too bad. \n",
      "white tux tails" : "A snazzy white tux, with tails.\n",
      "tux tails" : "A snazzy black tux, with tails. \n",
      "white tux" : "A traditional style tux, in white. \n",
      "black tux" : "A traditional tuxedo.\n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set( "exits", ([
      "west" : MALL+"mall4.c",
      "east" : MALL+"drsrm2.c",
    ]) );
}
