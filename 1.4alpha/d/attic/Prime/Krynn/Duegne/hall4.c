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
This is the end of the hallway. There is a door to either side
of you, each leading to a room. The hallway itself romms back
to the east towards the stairs leading down to the common room.
Endtext
);
set("exits" , ([
"east"  :  "/d/Prime/Krynn/Duegne/hall3.c",
"south" :  "/d/Prime/Krynn/Duegne/innroom7.c",
"north" :  "/d/Prime/Krynn/Duegne/innroom8.c",
"up"    :  "/d/Prime/Krynn/Duegne/attic1.c",
]));
set("exit_suppress", ({"up"}));
set("item_desc", ([
"hallway" : "The hallway runs east to west amd is lined with doors. The starirs leading down to the common room are to the east.\n",
"ceiling" : "As you look at the ceiling you see what might be a crack of some kind in it.\n",
"crack" : "As you look at the crack you notice it is a trap door and you open it.\n",
]));
}
