#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "An intersection.");
set("long",@Endtext
Main Street intersects here with both Lubine Way to your east
and Dragonesti Blvd. to your west. Main Street continues to both
your north and south.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road23.c",
"east"  :  "/d/Prime/Krynn/Duegne/road19.c",
"south" :  "/d/Prime/Krynn/Duegne/road15.c",
"north" :  "/d/Prime/Krynn/Duegne/road17.c",
]));
set("item_desc", ([
"road" : "The road splits here. Dragonesti Blvd lies to your west, while Peaceful Way lies to your east. Main street continues to the north and south.\n",
]));
}
