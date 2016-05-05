#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;

void create() {
  ::create();
  set("outside", "vieillere");
  set("light", 1);
  set("short", "A concrete road");
  set("long", @Endtext
Metal reinforcements protrude out of the unrepaired pavement.  Piles of
rubble and trash have been stacked on the sides of the road, making it
difficult to leave the main path.  Much of the trash consists of damaged
or destroyed mechanical devices.
Endtext
 );
  set("item_desc", ([
    "pavement" : "The concrete has been neglected for a long time.\n",
    "reinforcements" : "The metal reinforcements look like twisted fingers.\n",
    "rubble" : "There are a many chunks of concrete and rocks in the rubble.\n",
    "trash" : "They are mainly broken bottles and paper.\n",
    "devices" : "The devices are too damaged to do any good.\n",
  ]) );
  set("exits", ([
    "west"  : ROOMS+"hall",
    "south" : ROOMS+"road05",
  ]) );
  create_door("west", "east", "A metal door", "open");
}

