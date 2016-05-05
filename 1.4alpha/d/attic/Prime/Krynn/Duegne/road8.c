#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short","Dragon's Road East.");
set("long",@Endtext
Dragon's Road cuts through Duegne running east to west. Just to
the north of you are aprtments housing some of the cities residents.
The central part of the city is to the west while the Eastern Gate
is further to the east.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road7.c",
"east"  :  "/d/Prime/Krynn/Duegne/road9.c",
]));
set("item_desc", ([
"road" : "The cobblestone road continues east to west.\n",
"cobblestone" : "Smooth stones used to make the road.\n",
"apartments" : "This is where most of the cities residents live.\n",
"gate" : "The gate is still to far to the east for you to make it out clearly.\n",
]));
}
