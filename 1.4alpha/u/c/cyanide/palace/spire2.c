#include "main.h"

inherit MAIN+"/palacestd.c";

void create() {
    ::create();
    set("short", "A Stairwell");
    set("long", @EndText
You are at the top of a long, spiral stairwell. A simple wooden door
leads to the east, or you could go back down toward the base of the
spire.
EndText
    );
    set("exits", ([
      "east" : MAIN+"/waitingroom.c",
      "down" : MAIN+"/spire1.c",
    ]) );
    set("item_desc", ([
      "stairwell" : "It decends downward quite a ways.\n",
      "door" : "It is a simple wooden door. Oak, you think.\n",
    ]) );
}

/* EOF */
