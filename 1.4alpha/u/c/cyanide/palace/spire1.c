#include "main.h"

inherit MAIN+"/palacestd.c";

void create() {
    ::create();
    set("short", "A Stairwell");
    set("long", @EndText
You are standing on a long, spiral stairwell. A simple wooden door
leads to the east, or you could go back down toward the base of the
spire or continue upwards.
EndText
    );
    set("exits", ([
      "up" : MAIN+"/spire2.c",
      "east" : MAIN+"/library.c",
      "down" : MAIN+"/spireante.c",
    ]) );
    set("item_desc", ([
      "stairwell" : "It decends downward quite a ways.\n",
      "door" : "It is a simple wooden door. Oak, you think.\n",
    ]) );
    set("pre_exit_func", ([
    ]) );
}

int locked() {
    tell_object(TP, "The eastern door seems to be locked.\n");
    return 1;
}

/* EOF */
