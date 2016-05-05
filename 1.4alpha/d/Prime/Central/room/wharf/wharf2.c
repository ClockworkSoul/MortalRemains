
#include "central.h"

inherit ROOM;

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "A Wharf");
    set("long", @EndText
You are on a foggy wharf at the edge of the New Sea. The acrid smell of 
saltwater and the pungent stench of decomposing organic material is stong
enough to make your eyes water. The wharf continues to the east and west.
EndText
    );
    set("exits", ([
      "west" : M_ROOM+"wharf/wharf1.c",
      "east" : M_ROOM+"wharf/wharf3.c",
    ]) );
    set("item_desc", ([
      "fog" : "It seems to roll in from the water.\n",
      "water" : "It is dark, and not very clean.\n",
      "sea" : "It is dark, and not very clean.\n",
      "wharf" : "It is a long dock built at the edge of the water.\n",
      "road" : "It leads back to "+CITY_NAME+".\n",
      "warehouse" : "It appears abandoned.\n",
    ]) );
    set("smell", ([
      "default" : wrap("The amell of salty sea air and stench of decomposing "+
	"organic material is pungent enough to make your eyes water."),
    ]) );
    set("objects", ([
      "human" : M_MON+"dockworker.c",
    ]) );
    reset();
}

/* EOF */
