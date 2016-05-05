#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Gap");
    set("long", wrap(
	"As you walk in you realize the store is much bigger "+
	"than it appears from the outside. Racks of clothes "+
	"line the sides of the aisle. In the back of the store, "+
	"you can see matched sets of panties and bras. "+
	"A dressing room is west."
      ) );
    set("item_desc", ([
      "aisle" : "It is white and looks freshly waxed. \n",
      "clothes" : "They're trendy. \n",
      "matched sets" : "They match. \n",
      "sign" : "It says 'The Gap'. \n",
      "panties" : "They are blue and lacey. \n",
      "bra" : "It's padded! \n",
      "bras" : "They're sexy! \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "store" : "You're in it. \n",
      "racks" : "There are clothes on them. \n",
      "dressing room" : wrap("There is one of those "+
	"half doors which swing in or out. A lady asks "+
	"how many items. You tell her 1 and she hands you "+
	"a little plastic thing with the number one on it. "),
    ]) );
    set("objects" , ([
      "clerk" : MALL+"mons/clerk.c",
      "unhappy" : MALL+"mons/unhappy.c", 
    ]) );
    reset();
    set("listen" , "A Tori Amos song is playing. \n");
    set( "exits", ([
      "east" : MALL+"mall1.c",
      "west" : MALL+"drsrm.c",
    ]) );
}
