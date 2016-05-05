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
	"In the center of this area there is a large, and rather "+
	"decorative looking fountain. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "store" : "There are many of them. \n",
      "mall" : "You're in it DUH!\n",
      "east" : "Try looking east. \n",
      "west" : "Try looking west. \n",
      "sales" : "You don't see any good ones. \n",
      "stores" : "There are many of them. \n",
      "shop" : "Which one? \n",
      "shops" : "There aren't any right here. Try south or north. \n",
      "shoppers" : "Find one you can kill ok? \n",
    ]) );
    set("listen" , wrap("You fall down on your knees and thank the "+
	"lord that the fountain drowns out that godawful musak! \n") );
    set("objects" , (["fountain" : MALL+("fountain.c") ]) );
reset ();
set("smell" , "Something smells a bit fishy here. \n");
set( "exits", ([
  "south" : MALL+"mall4.c",
  "west" : MALL+"hall.c",
  "east" : MALL+"hall1.c",
  "north" : MALL+"mall6.c",
]) );
}

int reset() {
    object fountain = present("fountain", TO);

    if (fountain) fountain->fix_flag();

    return ::reset();
}
