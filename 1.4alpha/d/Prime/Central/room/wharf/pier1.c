
#include "central.h"

inherit ROOM;

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "Out on a Pier");
    set("long", @EndText
You are at the southern end of a long pier. The fog is so thisk you can 
barely make out the small waves that break against the dock.
EndText
    );
    set("exits", ([
    "north" : M_ROOM+"wharf/wharf1.c",
    ]) );
    set("item_desc", ([
    "fog" : "It seems to roll in from the water.\n",
    "water" : "It is dark, and not very clean.\n",
    "sea" : "It is dark, and not very clean.\n",
    "wharf" : "You can't see it through the fog.\n",
    "pier" : "You are at the end of it.\n",
    ]) );
    set("smell", ([
    "default" : wrap("The amell of salty sea air and stench of decomposing "+
        "organic material is pungent enough to make your eyes water."),
   	]) );
}

/* EOF */