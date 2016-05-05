#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("objects", ([
"citizen"  :  "/d/Prime/Krynn/mons/citizen2.c",
]));
reset();
set("light",1);
set("short", "Dragon's Road East.");
set("long",@Endtext
The road has a little less traffic here, being as it is not too
close to the city square. To the north and south of you are
aprtment complexes where most of the cities residents live. The
road continues to the east and west from here.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road6.c",
"east"  :  "/d/Prime/Krynn/Duegne/road8.c",
]));
set("item_desc", ([
"apartments" : "Large buildings used to house most of the cities residents.\n",
"road" : "The cobblestone road continues both east and west of here.\n",
"cobblestone" : "Smooth stones used to construct the road.\n",
"square" : "The square is too far away for you to make out anything in great detail.\n",
]));
}
