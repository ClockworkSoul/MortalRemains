#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Main Street.");
set("long",@Endtext
Main Street intersects here with Peace Street, which runs off to
the east. Main St. itself continue to the north towards the city
gates and south further into the city.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/road27.c",
"south" :  "/d/Prime/Krynn/Duegne/road17.c",
"north" :  "/d/Prime/Krynn/Duegne/road36.c",
]));
set("item_desc", ([
"road" : "The cobblestone road runs north and south here, with another smaller one branching off to the east.\n",
"cobblestone" : "Smooth stones used to make up the road.\n",
"gates" : "The gates are still to far off for you to make out anything in great detail.\n",
]));
}
