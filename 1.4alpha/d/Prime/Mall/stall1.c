#include "mall.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "A Dressing Room Stall");
    set("long", wrap(
	"This is a tiny stall where you can try on clothes before "+
	"you purchase them. A full length mirror hangs on the wall "+
	"right in front of you. On the left and right wall are "+
	"hooks and a small shelf, probably for a purse or something. "
      ) );
    set("item_desc", ([
      "stall" : "A thin curtain shields the customer from view. \n",
      "dress" : "Its ugly. \n",
      "clothes" : "They're ugly. \n",
      "number" : "It's 867-5309 \n",
      "floor" : "It is white and looks freshly waxed. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
      "mirror" : "You can see yourself in it. \n",
      "hook" : "There is an ugly red dress hanging on it. \n",
      "hooks" : "There are some really ugly clothes hanging on them \n",
      "shelf" : "It looks like someone left their number on it. \n",
      "curtain" : "It's so thin you can almost see through it. \n",
      "wall" : "It's a wall. \n",
      "right wall" : "It's a wall, to the right. \n",
      "left wall" : "It's a wall, to the left. \n",
      "something" : "Looks like a something. \n",
    ]) );
    set( "exits", ([
      "north" : MALL+"drsrm.c",
    ]) );
}
