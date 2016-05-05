#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Mall");
    set("long", wrap(
	"You are in the mall, on the main walkway. "+
	"Shops are on either side of you, and crazed shoppers "+
	"are still rushing past you, and knocking into you. "+
	"To the west is the toy store, and east is the Bride's Boutique."
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "store" : "There are many of them. \n",
      "stores" : "There are many of them. \n",
      "mall" : "You're in it DUH!\n",
      "sales" : "You don't see any good ones. \n",
      "east" : "Try looking east. \n",
      "west" : "Try lookint west. \n",
      "shops" : "West is the toy store, east is the Bride's Boutique. \n",
      "shop" : "One west, one east. \n",
      "shoppers" : "Find one you can kill ok? \n",
      "walkway" : "It is tiled. \n",
    ]) );
    set("listen" , "The elevator music rings in your head. \n");
    set( "exits", ([
      "south" : MALL+"mall1.c",
      "west" : MALL+"toy.c",
      "east" : MALL+"store5.c",
      "north" : MALL+"mall3.c"
    ]) );
}
