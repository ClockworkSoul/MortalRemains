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
	"This is the entrance to the great mall of _________. "+
	"The stores are all lined up on either side of the "+
	"walkway. Crazed shoppers rush by you in a mad frenzy, "+
	"trying to find the best sales. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Welcome to the Mall'. \n",
      "store" : "There are many of them. \n",
      "stores" : "There are many of them. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
    ]) );
    set( "exits", ([
      "west" : MALL+"store.c",
      "east" : "/u/h/herlsef/mall/store1.c",
      "north" : "/u/h/herself/mall/mall1.c"
    ]) );
}
