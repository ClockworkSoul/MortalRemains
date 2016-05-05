#include "mall.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Men's Room");
    set("long", wrap(
	"You walk into the men's lavatory. Urinals line the wall "+
	"opposite the sinks. Three stalls are at the far end. "+
	"they appear to be occupied. "
      ) );
    set("item_desc", ([
      "stall" : "You peek under the stall door. What a pervert! \n",
      "urinal" : "It looks like a urinal, people pee in it. \n",
      "sink" : "Oddly, it looks like it's never been used. \n",
      "floor" : "It is white and looks freshly waxed. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
      "toilet" : "Someone is using it. \n",
      "door" : "It has some lame ass jokes scribbled on it. \n",
    ]) );
    set( "exits", ([
      "east" : MALL+"hall3.c",
    ]) );
}
