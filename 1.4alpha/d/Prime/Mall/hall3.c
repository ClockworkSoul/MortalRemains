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
	"the west is the men's room, and east is the ladies' room. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set("listen" , "You can still hear the fountain splashing. \n");
    set( "exits", ([
      "west" : MALL+"lav.c",
      "east" : MALL+"lav1.c",
"north" : MALL+"hall2.c",
    ]) );
}
