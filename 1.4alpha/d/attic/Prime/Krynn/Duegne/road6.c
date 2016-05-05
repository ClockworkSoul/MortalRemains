#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Dragon's Road East.");
set("long",@Endtext
You are on Dragon's Road East just outside the main store which
is directly to your south. The city square is just to your west
while the road continues to the east.
Endtext
);
set("exits", ([
"west" : "/d/Prime/Krynn/Duegne/square.c",
"east" : "/d/Prime/Krynn/Duegne/road7.c",
"south" : "/d/Prime/Krynn/Duegne/build2.c",
]));
set("item_desc", ([
"square" : "All you can make out is a large throng of people moving about.\n",
"shop" : "You see a number of people buying and selling things inside.\n",
"road" : "The cobblestone road runs east to west through the city.\n",
"cobblestone" : "Smooth stones that have been placed together to make up ithe road.\n",
]));
}
