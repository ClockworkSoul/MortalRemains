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
You stand on Main Street just inside the gates of Duegne. Main St.
runs through the city from the north to the south. To you north
are where the gates stand, while the road continues south deeper
into the city itself.
Endtext
);
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne/road18.c",
"north"  :  "/d/Prime/Krynn/Duegne/gates4.c",
]));
set("item_desc", ([
"road"  :  "The road is made of cobblestone and runs north to south.\n",
"cobblestone"  :  "Small stones used to make up the road.\n",
"gates" : "The gates stand just tp your north and from here you can see that they are magnificant structures which serve their purpose well.\n",
]));
}
