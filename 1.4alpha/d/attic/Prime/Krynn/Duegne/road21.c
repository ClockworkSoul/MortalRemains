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
You stand on Lubine way just south of a small house. To your
west lies Main St. while Lubine runs further east.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road20.c",
"east"  :  "/d/Prime/Krynn/Duegne/road22.c",
"north" :  "/d/Prime/Krynn/Duegne/build16.c",
]));
set("item_desc", ([
"house" : "A small house that looks like someone lives in.\n",
"road" : "A cobblestone road that runs east and west here, with a small house to your north.\n",
"cobblestone" : "Smooth stones that were used to make up the road.\n",
]));
}
