#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A school room");
set("long", @Endtext
You have entered what appears to be a classroom. There are a
bunch of small tables and benches throughout the tiny room.
Along the walls are some shelves containing books and the
belongings of some of the children. To the back of the room
is a large chalk board. You think there may be something written
on the board. The only exit is the way you came in.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/road15.c",
]));
set("item_desc", ([
"benches"  :  "Small benches where the children sit during classes.\n",
"tables"  :  "Small tables whith benches attached to them.\n",
"shelves"  :  "Large shelves that hold some books and other small things belonging to the children. Nothing worth taking though, I mean come on, they are only kids.\n",
"board"  :  "You take a closer look at the board and you think that it reads, 'School sucks some major ass.' Nice kids they have here huh?\n",
]));
}
