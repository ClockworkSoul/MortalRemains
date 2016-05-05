#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A kitchen.");
set("long",@Endtext
The kitchen is rather warm from the huge oven cooking the bread
and the big cauldron cooking the soup. YOu also can not help
notice the huge firepit where some piece of a dead animal is 
cooking. Serving maids and th Innkeeper's wife are running about
trying to get everything done. There is a door at the far end that
leads out to the back of the Inn.
Endtext
);
set("exits", ([
"door" : "/d/Prime/Krynn/Duegne/yard1.c",
"common" : "/d/Prime/Krynn/Duegne/common.c",
]));
set("item_desc", ([
"cauldron" : "A huge pot used for making the soup.\n",
"firepit" : "A huge firepit where some beast is roasting nicely. You mouth starts to water just looking at it.\n",
"oven" : "A huge brick oven where they are baking the bread.\n",
"maids" : "Maids running about trying to avoid the rath of the Innkeeper's wife.\n",
"wife" : "A stout woman shouting orders to the serving maids and looking mighty upset as she does it.\n",
]));
}
