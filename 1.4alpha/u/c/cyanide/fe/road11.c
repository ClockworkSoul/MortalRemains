#include <mudlib.h>
#include <path.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("light", 1);
  set("short", "A concrete road");
  set("long", @Endtext
Broken items litter the road, most being piled up on the sides of
the path.  An oil barrel is near the side of the road with some
burning pieces of trash inside of it.  Dirty footprints surround the
barrel, revealing that it's a common gathering place for the homeless.
Endtext
 );
  set("item_desc", ([
    "items" : "They are pieces of junk that are probably worthless.\n",
    "barrel" : "It is kept burning with the trash on the streets.\n",
    "footprints" : "The footprints mainly surround the burning barrel.\n",
  ]) );
  set("exits", ([
    "east"  : ROOMS+"road12",
    "west"  : ROOMS+"road10",
  ]) );
  set("objects", ([ "man" : MOBS+ "homeless"  ]) );
  reset();
}

