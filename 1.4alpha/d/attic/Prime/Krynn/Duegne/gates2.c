#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("objects", ([
"guard"  :  "/d/Prime/Krynn/mons/gateguard.c",
"guard1" :  "/d/Prime/Krynn/mons/gateguard.c",
]));
reset();
set("light",1);
set("forbidden", 1);
set("short","Western Gates of Duegne.");
set("long",@Endtext
You stand before the western gates of the ancient city of 
Duegne. The gates are made entirely of gold and both are engraved
with a dragon. They look more ornamental then functional but 
something tells you that they serve their purpose well.
The road continues west out of the city and east towards the
city square.
Endtext
);
set("exits", ([
"east" : "/d/Prime/Krynn/Duegne/road13.c",
]));
set("item_desc", ([
"gates" : "Two golden gates, each engraved with a dragon. They look v3ery heavy and like they would do their job well.\n",
"gate" : "The gate is made of solid gold and engraved in the middle is a dragon, which looks to be protecting the city.\n",
"road" : "The road become cobblestone here and leads into the heart of the city.\n",
"cobblestone" : "Small square stones that have been fitted together to make a road.\n",
]));
}
