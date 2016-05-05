#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "A Hallway");
    set("long", wrap(
	"You are standing in a very plain hallway. It appears to be "+
	"a dead end. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "hall" : "It's plain. \n",
      "hallway" : "It's very plain looking. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set( "exits", ([
      "west" : MALL+"mall5.c",
    ]) );
}
void reset() {

    object ob;

    if(!present("man")) {
	ob = clone_object(MALL+"mons/guy.c");
	ob->move(TO);
	ob = clone_object(MALL+"mons/guy.c");
	ob->move(TO);
    }

    if(!present("shopper", TO)) {
	ob = clone_object(MALL+"mons/shopper.c");
	ob->move(TO);
    }
}
