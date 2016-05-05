#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short", "Sox");
    set("long", wrap(
	"This store sells nothing but socks. Looking around you see "+
	"all different types. Striped, plaid, solid colored, "+
	"multi-colored, and they come in all different sizes too. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Sox'. \n",
      "socks" : "There are so many of them. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set( "exits", ([
      "east" : MALL+"mall2.c",
    ]) );
}
