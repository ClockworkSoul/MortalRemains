#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "Town Square");
set("long",@Endtext
This is the town square of Duegne. Drache Lane is crossed here by
Silvara Street. Most of the buildings here are in terrible shape.
It seems that what ever destroyed this town, hit here the hardest.
The buildings are lying across the roads on all sides allowing you
only exit back from where you came.
Endtext
);
set("item_desc", ([
"square" : "The town square of Duegne. What ever was once here has long since been destroyed. There is nothing here but rubble.\n",
"street" : "The street is cluttered with fallen debri from the destruction of the town.\n",
"buildings" : "What once were probably shops and homes are now nothing more than ruin and decay. They clutter the two streets on either side blocking nearly every exit.\n",
"road" : "It is made from dirt which has been packed hard over time.\n",
]));
set("search_desc", ([
"square" : "You find nothing but scattered rubble and debri from the fallen buildings.\n",
"street" : "You find nothing but dirt and debri.\n",
"buildings" : "As you begin to inspect the buildings some stone begins to fall upon you. You decide that they are very unsafe and back away.\n",
"road" : "You find nothing of interest.\n",
]));
set("exits", ([
"south"  :  "/d/Dark/Duegne/Ruin/town3.c",
]));
set("objects", ([
"bones" : "/d/Dark/Duegne/monsters/dracolich.c",
]));
::create();
}
