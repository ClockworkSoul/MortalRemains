#include <mudlib.h>
#include <central.h>

inherit ROOM;
inherit DOORS;
  object whore;

void reset() { 
   if (!whore) {

      whore = clone_object("/d/Prime/Central/mon/whore") ;
    whore->move(TO) ;
  }
}


void create() {
    set("light", 1);
    set("short", RD_Y);
    set("long", @Endtext
Metal reinforcements protrude out of the unrepaired pavement. Piles of
rubble and trash have been stacked on the sides of the road, making it
difficult to leave the main path. Much of the trash consists of damaged
or destroyed mechanical devices.
Endtext
    );
    set("author", "cyanide");
    set("item_desc", ([
      "pavement" : "The concrete has been neglected for a long time.\n",
      "reinforcements" : "The metal reinforcements look like twisted fingers.\n",
      "rubble" : "There are a many chunks of concrete and rocks in the rubble.\n",
      "trash" : "They are mainly broken bottles and paper.\n",
      "devices" : "The devices are too damaged to do any good.\n",
    ]) );
    set("exits", ([
      "north" : M_ROOM+"road0_-2",
      "south" : M_ROOM+"road0_-4",
    ]) );
   ::create() ;
    reset() ;
}

