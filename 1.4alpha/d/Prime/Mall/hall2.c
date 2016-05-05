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
	"You are standing in a very plain looking hallway. To "+
	"the north is the security office, and south are the restrooms. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "hall" : "It's very plain. \n",
      "hallway" : "It's very plain looking.\n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set("listen" , "You can still hear the fountain splashing. \n");
    set( "exits", ([
      "north" : MALL+"sec.c",
      "south" : MALL+"hall3.c",
      "east" : MALL+"hall.c",
    ]) );
}
