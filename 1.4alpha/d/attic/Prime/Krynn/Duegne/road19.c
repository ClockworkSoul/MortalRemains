#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Lubine Way.");
set("long",@Endtext
Lubine Way runs eastwards off of Main St. To your north you
notice what seems to be a small house of some kind and you
also notice that there are more of these further down the
road. Main St. is just to your west.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road16.c",
"east"  :  "/d/Prime/Krynn/Duegne/road20.c",
"north" :  "/d/Prime/Krynn/Duegne/build15.c",
]));
set("item_desc", ([
"house" : "A small house that looks like someone lives in.\n",
"road" : "A cobblestone road that runs east and west here, with a small house to your north.\n",
"cobblestone" : "Smooth stones that were used to make up the road.\n",
]));
}
