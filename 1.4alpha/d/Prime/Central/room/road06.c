#include <mudlib.h>
#include <central.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("short", "A concrete road");
    set("long", @Endtext
This small side road appears to lead into a small junk yard. Many
pieces of trash continue to litter the sides of the road. Strangely,
most of the items are mechanically related. The side street continues
north, through a clear path into the trash heap. A slight buzzing of
electricity can be heard from somewhere north.
Endtext
    );
    set("item_desc", ([
      "items" : "A few broken gears and wires can be seen,\n",
      "trash" : "They are strewn about the road, discarded and useless.\n",
    ]) );
    set("exits", ([
      "north" : M_ROOM+"road03",
      "southwest" : M_ROOM+"road12",
    ]) );
}

