
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
and a dark and narrow path leads to the northwest around the back of a 
warehouse and up a hill. A long wooden pier leads into the water to the 
south, getting lost in the fog. There is a small sign here.
EndText
    );
    set("exits", ([
      "northwest" : M_ROOM+"wharf/path1.c",
      "south" : M_ROOM+"wharf/pier1.c",
      "east" : M_ROOM+"wharf/wharf2.c",
      //"north" : M_ROOM+"wharf/warehouse1.c",
    ]) );
    set("item_desc", ([
      "fog" : "It seems to roll in from the water.\n",
      "water" : "It is dark, and not very clean.\n",
      "sea" : "It is dark, and not very clean.\n",
      "wharf" : "It is a long dock built at the edge of the water.\n",
      "road" : "It leads back to "+CITY_NAME+".\n",
      "sign" : "The sign reads: Pier 1.\n",
      "pier" : "It entends to the south, getting lost in the fog.\n",
      "warehouse" : "It appears abandoned.\n",
    ]) );
    set("smell", ([
      "default" : wrap("The smell of salty sea air and stench of decomposing "+
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
	write("The sign reads: Pier 1.\n");
    else
	write("Read what?\n");

    return 1;
}



/* EOF */
