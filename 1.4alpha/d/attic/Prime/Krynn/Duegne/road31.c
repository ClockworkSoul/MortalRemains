#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short","Sunshine Way.");
set("long",@Endtext
Sunshine Way runs west off of Main Street. At the end of the 
street, you see what appears to be a very large and oppressive
building. Main Street lies to your east.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road32.c",
"east"  :  "/d/Prime/Krynn/Duegne/road2.c",
]));
set("item_desc", ([
"road" : "The road branched of of Main St. and runs east to west here. Like the other roads, this is also made from cobblestones.\n",
"cobblestone" : "Smooth stones that make up the road.\n",
"building" : "You are still a little too far away to make it out completely. It just looks big and dark from here.\n",
]));
}
