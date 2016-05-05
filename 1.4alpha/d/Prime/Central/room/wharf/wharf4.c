
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
enough to make your eyes water. The wharf continues to the east and west,
and an abandomed warehouse lay to the north. A long wooden pier leads into
the water to the south, getting lost in the fog. There is a small sign 
here.
EndText
    );
    set("exits", ([
      "south" : M_ROOM+"wharf/pier2.c",
      "west" : M_ROOM+"wharf/wharf3.c",
      "east" : M_ROOM+"wharf/wharf5.c",
      /*
      "north" : M_ROOM+"wharf/warehouse2.c",
      */
    ]) );
    set("item_desc", ([
      "fog" : "It seems to roll in from the water.\n",
      "warehouse" : "It appears abandoned.\n",
      "water" : "It is dark, and not very clean.\n",
      "sea" : "It is dark, and not very clean.\n",
      "wharf" : "It is a long dock built at the edge of the water.\n",
      "sign" : "The sign reads: Pier 2.\n",
      "pier" : "It entends to the south, getting lost in the fog.\n",
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

void init() {
    add_action("read_func", "read");
}

int read_func(string str) {
    if (str && str=="sign")
	write("The sign reads: Pier 2.\n");
    else
	write("Read what?\n");

    return 1;
}



/* EOF */
