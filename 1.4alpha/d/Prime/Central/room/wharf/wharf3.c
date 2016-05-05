
#include "central.h"

inherit ROOM;

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", "A wharf.") ;
    set("long", @EndText
You are on a foggy wharf at the edge of the New Sea. The acrid smell of 
saltwater and the pungent stench of decomposing organic material is stong
enough to make your eyes water. The wharf continues to the east and west,
and a dark and narrow road leads back the the city to the north.
EndText
    );
    set("exits", ([
      "west" : M_ROOM+"wharf/wharf2.c",
      "east" : M_ROOM+"wharf/wharf4.c",
      "north" : M_ROOM+"road-2_-6.c",
    ]) );
    set("item_desc", ([
      "fog" : "It seems to roll in from the water.\n",
      "water" : "It is dark, and not very clean.\n",
      "sea" : "It is dark, and not very clean.\n",
      "wharf" : "It is a long dock built at the edge of the water.\n",
      "road" : "It leads back to "+CITY_NAME+".\n",
    ]) );
    set("smell", ([
      "default" : wrap("The amell of salty sea air and stench of decomposing "+
	"organic material is pungent enough to make your eyes water."),
    ]) );
    set("objects", ([
      "human" : M_MON+"dockworker.c",
    ]) );
    ::create() ;
    reset() ; 
}

/* EOF */
