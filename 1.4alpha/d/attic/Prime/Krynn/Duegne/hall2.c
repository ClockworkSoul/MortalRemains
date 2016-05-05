#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A hallway.");
set("long", @Endtext
The hallway is empty except for yourself. There are doors to 
your north and you south. The hallway runs further west towards
more rooms and east to the stairs.
Endtext
);
set("exits" , ([
"west"  :  "/d/Prime/Krynn/Duegne/hall3.c",
"east"  :  "/d/Prime/Krynn/Duegne/hall1.c",
"south" :  "/d/Prime/Krynn/Duegne/innroom3.c",
"north" :  "/d/Prime/Krynn/Duegne/innroom4.c",
]));
set("item_desc", ([
"hallway" : "The hallway runs east to west amd is lined with doors. The starirs leading down to the common room are to the east.\n",
]));
}
