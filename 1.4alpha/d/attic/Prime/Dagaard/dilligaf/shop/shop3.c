#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit PUB;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "The Stage Room" );
  set( "long" , @EndText
  You have entered the Stage Room. One of the prides of the
  establishment. Seated at about 25 tables are various men smoking
  cigars and drinking. Milling about the tables are women, scantlily
  clad in bikini-thong underwear, taking drink orders.

  The commands here are: menu, buy <drink>, powerheal <drink>.

EndText
  );
  set( "exits", ([
    "out" : SHOPS+"shop2.c",
  ]) );
  set("item_desc" , ([
    "stage" : "\n"+
    "It is an enourmous stage with blazing lights and loud music\n"+
    "the wood seems to be pressure treated, and won't need to be\n"+
    "replaced for quite some time.\n",
    "men" : "Sitting around enjoying their cigars and drinks.\n",
    "women" : "\n"+
    "Veloptuous women with their asses exposed. Walking about with\n"+
    "menus and drinks. Beware if you touch them, the bouncers don't\n"+
    "take too kindly to it.\n",
    "underwear" : "Do I have to draw you a picture too?\n",
    "tables" : "Large wooden things. Imagine that.\n",
  ]));
}
