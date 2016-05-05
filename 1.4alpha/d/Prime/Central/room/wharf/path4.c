inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "At A Fork");
    set("long", @EndText
You suddenly find yourself a fork in the path. The main path makes slight
left bend, and continues in a westerly direction. A smaller, even more 
overgrown path leads north.
EndText
    );
    set("exits", ([
      "west" : M_ROOM+"wharf/lhousebase.c",
      "north" : M_ROOM+"wharf/path5.c",
      "southeast" : M_ROOM+"wharf/path3.c",
    ]) );
    set("pre_exit_func", ([
      "west" : "no_func",
    ]) );
    set("item_desc", ([
      "fog" : "You seem to have climbed above it.\n",
      "overgrowth" : "It is quite lush back here.\n",
      "ladder" : "It is very old and rusty, but it should hold your weight.\n",
    ]) );
    set("exit_msg", ([
      "west" : "$N wanders down the westward path.\n",
      "north" : "$N pushes through the overgrowth to the north.\n"
    ]) );
    set("smell", ([
      "default" : wrap("The amell of salty sea air is strong here."),
    ]) );
}

int no_func() {
    write("That room isn't done yet.\n");
    return 1;
}

/* EOF */
