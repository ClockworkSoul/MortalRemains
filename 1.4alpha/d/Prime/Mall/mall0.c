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
	"This is the entrance to the 'Four Winds' Mall. "+
	"The stores are all lined up on either side of the "+
	"walkway. Crazed shoppers rush by you in a mad frenzy, "+
	"trying to find the best sales. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "shoppers" : "Find one you can kill. \n",
      "sign" : "It says 'Welcome to the Mall'. \n",
      "mall" : "You're in it DUH!\n",
      "sales" : "You don't see any good ones. \n",
      "store" : "There are many of them. \n",
      "stores" : "There are many of them. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
    ]) );
    set("forbidden", 1);
    set("listen" , "You hear elevator music. \n");
    set( "exits", ([
      "south" : "/d/Prime/Central/room/road0_5.c",
      "north" : MALL+"mall.c",
    ]) );
}
