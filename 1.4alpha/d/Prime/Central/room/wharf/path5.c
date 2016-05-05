inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "On An Overgrown Path");
    set("long", @EndText
You are pushing your way through a neglected and ovegrown path deep in the
woods. The path itself is rather twisty, but leads generally north and 
south from here. It appears that to the north, the overgrowth thins out a
bit.
EndText
    );
    set("exits", ([
      "north" : "/d/Prime/Cyanide/area1/a1path01.c",
      "south" : M_ROOM+"wharf/path4.c",
    ]) );
    set("item_desc", ([
      "fog" : "You seem to have climbed above it.\n",
      "overgrowth" : "It is quite lush back here, but thins to the north.\n",
    ]) );
    set("exit_msg", ([
      "north" : "$N pushes through the overgrowth to the north.\n",
      "south" : "$N pushes through the overgrowth to the south.\n"
    ]) );
    set("smell", ([
      "default" : "The loamy smell of a forest mingles with the salty"+
      " sea air.\n",
    ]) );
}

/* EOF */
