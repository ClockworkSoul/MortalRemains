#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "North of square.");
set("long",@Endtext
You are standing just north of the city square. You can see
numerous people bustling about the square. To your east stands
an old warehouse while to your west is the entrance to the city
library. Main street continues to the north and south.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/build8.c",
"east"  :  "/d/Prime/Krynn/Duegne/build7.c",
"south" :  "/d/Prime/Krynn/Duegne/square.c",
"north" :  "/d/Prime/Krynn/Duegne/road15.c",
]));
set("item_desc", ([
"square" : "You look south towards the square and all you can make out is the mass of people that are in it.\n",
"warehouse" : "An old warehouse that has been used to store various things over the year.\n",
"road" : "The road continues both north and south of here.\n",
]));
}
