#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("objects", ([
"citizen" : "/d/Prime/Krynn/mons/citizen.c",
]));
reset();
set("light",1);
set("short", "Main Street.");
set("long",@Endtext
You stand on Main Street were it connects with Sunshine Way. You
can now see some buildings to the north on Main St. and looking 
down Sunshine Way you can make out the outline of a very odd
structure. To the south the street leads to the gates and out
into the forest.
Endtext
);
set("exits", ([
"north" : "/d/Prime/Krynn/Duegne/road3.c",
"south" : "/d/Prime/Krynn/Duegne/road1.c",
"west"  : "/d/Prime/Krynn/Duegne/road31.c",
]));
set("item_desc", ([
"buildings" : "The buildings rise above the horizon to the north.\n",
"structure" : "The structure is a little too far down the way for you to make it out in any detail. All you can tell is that it has a very peculiar shape to it.\n",
"road" : "The road continues to both the north and south with a branch to the west.\n",
]));
}
