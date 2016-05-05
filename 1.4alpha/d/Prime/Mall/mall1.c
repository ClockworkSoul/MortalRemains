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
	"To the west is The Gap, and east is The Wild Pair. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "store" : "There are many of them. \n",
      "stores" : "There are many of them. \n",
      "sales" : "You don't see any good ones. \n",
      "east" : "Try looking east. \n",
      "west" : "Try looking west. \n",
      "mall" : "You're in it DUH! \n",
      "shop" : "There is The Gap west, and The Wild Pair east.\n",
      "shops" : "The Gap is west, and The Wild Pair is east. \n",
      "shoppers" : "Find one you can kill ok? \n",
    ]) );
    set("listen", "The elevator music is getting more annoying. \n");
    set("objects" , ([
      "teen" : MALL+"mons/teeny.c",
    ]) );
    reset();
    set( "exits", ([
      "south" : MALL+"mall.c",
      "north" : MALL+"mall2.c",
      "west" : MALL+"store2.c",
      "east" : MALL+"store3.c"
    ]) );
}
