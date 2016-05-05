#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;

void create() {
  ::create();
  set("light", 1);
  set("short", "A concrete road");
  set("long", @Endtext
The street here has been somewhat well kept.  A few stacks of trash
line the street, blocking several condemed stores.  A brick building
stands to the east with a small sign by the door.  The local bank is
west of here, continuing to serve the public in these dark times.
Endtext
 );
  set("item_desc", ([
    "trash" : "The trash contains mainly paper and other household wastes.\n",
    "stores" : "They have been vacant for quite some time.\n",
    "building" : "An old building which is still in use by citizens.\n",
    "sign" : "Rooms available for rent.\n",
  ]) );
  set("exits", ([
    "north" : ROOMS+"road14",
    "east"  : APT+"hall00",
    "west"  : ROOMS+"bank",
  ]) );
  create_door("west", "east", "A solid metal door", "open");
  create_door("east", "west", "An old wooden door", "locked");
}

