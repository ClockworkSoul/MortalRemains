#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("objects", ([
"citizen"  :  "/d/Prime/Krynn/mons/citizen4.c",
]));
reset();
set("light",1);
set("short", "South of square.");
set("long",@Endtext
You are on Main Street just south of the city square. All around
you the city is filled with people of all races hustling to and
fro doing thier days business. To the east of you is the main
store of the city while to the west is the main pub called the
"Talisman Tavern". From the looks of it it seems quite busy.
Endtext
);
set("exits", ([
"north" : "/d/Prime/Krynn/Duegne/square.c",
"south" : "/d/Prime/Krynn/Duegne/road3.c",
"west"  : "/d/Prime/Krynn/Duegne/build3.c",
"east"  : "/d/Prime/Krynn/Duegne/build2.c",
]));
set("item_desc", ([
"street" : "The street seems to be lined with people hustling about thier business.\n",
"tavern" : "The tavern seems to be quite full and rowdy.\n",
"store"  : "The store looks plain but by the number of people coming in and out of the place you know it is doing a good trade.\n",
"square" : "Just to the north you can make out the city square though it is too jammed with people to make out any specifics from here.\n",
]));
}
