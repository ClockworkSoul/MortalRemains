inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "Cliff Base");
    set("long", @EndText
After what seems like hours, you reach a dead end where the path reaches
the base of a small cliff. You can just barely make out an ancient, rusty
ladder leading up the cliff, obscured beneach decades of undergrowth and 
a pile of old discarded tires.
EndText
    );
    set("exits", ([
      "up" : M_ROOM+"wharf/path3.c",
      "east" : M_ROOM+"wharf/path1.c",
    ]) );
    set("item_desc", ([
      "fog" : "It's not as thick back here.\n",
      "overgrowth" : "It is quite lush back here.\n",
      "ladder" : "It is very old and rusty, but it should hold your weight.\n",
      "pile" : "Just a bunch of old tires, each holding smelly, black water.\n",
      "tires" : "Just a bunch of old tires, each holding smelly, black water.\n",
      "tire" : "Which one? There's a whole pile there!\n",
      "water" : "You really don't want to...\n",
      "cliff" : "It seems to be only about 3 or 4 meters high.\n",
    ]) );
    set("exit_msg", ([
      "up" : "$N carefully climbs the old, rusty ladder.\n"
    ]) );
    set("smell", ([
      "water" : "It's been standing for months. YUCK!\n",
      "default" : wrap("The smell of salty sea air is strong here."),
    ]) );
}

/* EOF */
