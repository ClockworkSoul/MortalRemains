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
	"To the west is a jewelry store, and east is the Tux Shop. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "store" : "There are many of them. \n",
      "stores" : "There are many of them. \n",
      "sales" : "You don't see any good ones. \n",
      "mall" : "You're in it DUH! \n",
      "east" : "Try looking east. \n",
      "west" : "Try looking west. \n",
      "shops" : "West is a jewelry store, and east is the Tux Shop. \n",
      "shop" : "Which one? \n",
      "shoppers" : "Find one you can kill ok? \n",
    ]) );
    set("listen" , "Your head is throbbing from the elevator music. \n");
    set( "exits", ([
      "south" : MALL+"mall3.c",
      "north" : MALL+"mall5.c",
      "west" : MALL+"store8.c",
      "east" : MALL+"store9.c",
    ]) );
}
