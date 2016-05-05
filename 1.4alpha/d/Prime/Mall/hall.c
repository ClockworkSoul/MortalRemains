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
	"the west there is another hallway where you can "+
	"find the restrooms and security office. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Foot Locker'. \n",
      "hall" : "It's very plain. \n",
      "hallway" : "It's very plain looking. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set("listen" , "You can still hear the fountain splashing. \n");
    set("objects" , (["man" : MALL+("mons/guy.c") ]) );
reset();
set( "exits", ([
  "east" : MALL+"mall5.c",
  "west" : MALL+"hall2.c",
]) );
}
