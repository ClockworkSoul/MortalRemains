#include "main.h"

inherit MAIN+"/palacestd.c";

void create() {
    ::create();
set("short", "Inside a broken aquarium");
    set("long", @EndText
This will be an aquarium.
EndText
    );
    set("exits", ([
      "west" : MAIN+"/library.c",
    ]) );
    set("item_desc", ([
      "stairwell" : "It decends downward quite a ways.\n",
      "door" : "It is a simple wooden door. Oak, you think.\n",
    ]) );
}

/* EOF */
