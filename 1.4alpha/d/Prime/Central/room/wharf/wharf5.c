
#include "central.h"

inherit ROOM;

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "End of the Wharf");
    set("long", @EndText
You are on a foggy wharf at the edge of the New Sea. The acrid smell of 
saltwater and the pungent stench of decomposing organic material is stong
enough to make your eyes water. The wharf continues back to the east, and
an abandomed warehouse lay to the north. A long wooden pier leads into the
water to the south, getting lost in the fog. There is a small sign here.
A small sandy path runs into the beachgrass to the east.
EndText
    );
    set("exits", ([
      "west" : M_ROOM+"wharf/wharf4.c",
      "south" : M_ROOM+"wharf/pier3.c",
      "southeast" : "/d/Prime/Central/room/wharf/path6.c",
      /*
	    "north" : M_ROOM+"wharf/warehouse3.c",
      */
    ]) );
    set("item_desc", ([
      "path" : "It runs to the east, toward a beach.\n",
      "warehouse" : "It appears abandoned.\n",
      "fog" : "It seems to roll in from the water.\n",
      "water" : "It is dark, and not very clean.\n",
      "sea" : "It is dark, and not very clean.\n",
      "wharf" : "It is a long dock built at the edge of the water.\n",
      "road" : "It leads back to "+CITY_NAME+".\n",
      "sign" : "The sign reads: Pier 3.\n",
      "pier" : "It entends to the south, getting lost in the fog.\n",
    ]) );
    set("smell", ([
      "default" : wrap("The amell of salty sea air and stench of decomposing "+
	"organic material is pungent enough to make your eyes water."),
    ]) );
}

void init() {
    add_action("read_func", "read");
}

int read_func(string str) {
    if (str && str=="sign")
	write("The sign reads: Pier 3.\n");
    else
	write("Read what?\n");

    return 1;
}



/* EOF */
