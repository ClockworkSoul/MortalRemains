#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short","Dragon's Road West.");
set("long",@Endtext
You are standing just east of Duegne's western gate. You can make
out the golden gates with the engraved dragons as they glitter
in the light. You can make out the beginning of the forest
through the gates.
Endtext
);
set("exits", ([
"west" : "/d/Prime/Krynn/Duegne/gates2.c",
"east" : "/d/Prime/Krynn/Duegne/road12.c",
]));
set("item_desc", ([
"gates" : "The golden gates of Duegne shine with the light reflecting off of them. You will have to get closer to get a better look at them.\n",
"forest" : "You can see what looks likes the beginning of a forest through the open gates.\n",
]));
}
