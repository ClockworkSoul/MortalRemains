#include "mall.h"
#include <mudlib.h>

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
	"The stores are all lined up on either side of the "+
	"walkway. Crazed shoppers rush by you in a mad frenzy, "+
	"trying to find the best sales. "+
	"To the west is Foot Locker, and east is Harmony House. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "east" : "Try looking east. \n",
      "west" : "Try looking west. \n",
      "mall" : "You're in it DUH! \n",
      "store" : "There are many of them. \n",
      "stores" : "There are many of them. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
      "shoppers#crazed shoppers" : "Find one you can kill... ok?\n",
      "sales" : "You don't see any good ones. \n", 
    ]) );
    set("listen" , "You hear elevator music. \n");
    set( "exits", ([
      "west" : MALL+"store.c",
      "east" : MALL+"store1.c",
      "south" : MALL+"mall0.c",
      "north" : MALL+"mall1.c"
    ]) );
}

// Cyanide added this
void reset() {
    object ob;

    if (!present("shopper")) {
	ob = clone_object(MALL+"mons/shopper.c");
	ob->move(TO);
	ob = clone_object(MALL+"mons/shopper.c");
	ob->move(TO);
    }

    if (!present("man", TO)) {
	ob = clone_object(MALL+"mons/guy.c");
	ob->move(TO);
    }
}
