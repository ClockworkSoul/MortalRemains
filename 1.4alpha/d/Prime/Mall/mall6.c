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
	"This seems to be the end of the mall. A dead end. "+
	"There is nothing here, so don't bother looking. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "mall" : "You're in it DUH!\n",
      "sales" : "You don't see any good ones. \n",
      "east" : "Try looking east. \n",
      "store" : "There are many of them. \n",
      "stores" : "There are many of them. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
    ]) );
    set("listen" , "You hear elevator music. \n");
    set( "exits", ([
      "south" : MALL+"mall5.c",
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
