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
This is the eastern portion of Dragon's Road, which runs through
the city of Duegne. To the east of you is the Eastern gate and
the road continues to the west towards the cities center. Just
to your west you see an inn,
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road9.c",
"east"  :  "/d/Prime/Krynn/Duegne/gates3.c",
]));
set("item_desc", ([
"road" : "The cobblestone orad runs through the city east to west.\n",
"cobblestone" : "Smooth stones which make up the road.\n",
"gate" : "The massaive gate stands just to your east.\n",
"inn" : "The inn is just off to your west a bit.\n",
]));
}
