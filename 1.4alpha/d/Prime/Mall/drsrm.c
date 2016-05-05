#include "mall.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "A Dressing Room");
    set("long", wrap(
	"You are in a small dressing room, to the north and south are "+
	"tiny stalls where people are trying on clothes. "
      ) );
    set("item_desc", ([
      "stall" : "A thin curtain shields the customer from view. \n",
      "floor" : "It is white and looks freshly waxed. \n",
      "stalls" : "They are only shielded by a thin curtain. \n",
      "curtain" : "It's so thin you can almost see through it. \n",
      "dressing room" : "You are in it. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
    ]) );
    set( "exits", ([
      "north" : MALL+"stall.c",
      "east" : MALL+"store2.c",
      "south" : MALL+"stall1.c",
    ]) );
}
