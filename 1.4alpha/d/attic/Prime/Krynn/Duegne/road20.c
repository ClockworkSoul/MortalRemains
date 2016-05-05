#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("objects", ([
"citizen"  :  "/d/Prime/Krynn/mons/citizen.c",
]));
reset();
set("short", "Lubine Way.");
set("long",@Endtext
Lubine Way runs eastwards off of Main St. To your north you
notice what seems to be a small house of some kind and you
also notice that there are more of these further down the
road. Main St. is further down to your west.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road19.c",
"east"  :  "/d/Prime/Krynn/Duegne/road21.c",
"north" :  "/d/Prime/Krynn/Duegne/build17.c",
]));
set("item_desc", ([
"house" : "A small house that looks like someone lives in.\n",
"road" : "A cobblestone road that runs east and west here, with a small house to your north.\n",
"cobblestone" : "Smooth stones that were used to make up the road.\n",
]));
}
