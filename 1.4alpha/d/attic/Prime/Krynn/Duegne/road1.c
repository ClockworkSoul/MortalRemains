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
You stand at the end of Main Street, one of the two main roads
that run through Duegne. Once a bustling thruway, the traffic
has died down over the years. The road, made up of cobblestones
has begun to become a little overgrown. Main Street runs north
further into the city and south towards its gates.
Endtext
);
set("exits",([
"north" : "/d/Prime/Krynn/Duegne/road2.c",
"south" : "/d/Prime/Krynn/Duegne/gates1.c",
]));
set("item_desc", ([
"road" : "An ancient cobblestone road that was once a major artery for the city. It has become slighty overgrown the last few years du to a lack of use.\n",
"stone" : "Small cobblestones that make up the road. Small weeds and crabgrass are begining to pop through the cracks.\n",
"weeds" : "Small weeds which or popping up through cracks in the stone.\n",
"grass" : "Crabgrass which is starting to break through the cracks in the stone.\n",
"cracks" : "Small breaks where the cobblestone was placed next to each other which have expanded over time.\n",
]));
}
