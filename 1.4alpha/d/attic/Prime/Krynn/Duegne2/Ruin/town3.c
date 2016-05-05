#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "Drache Lane");
set("long", @Endtext
You stand on Drache Lane, one of the main street running through
Duegne. On either side of you rise tall abandoned buildings which
are just like the others you have seen in the town. You notice that
on the building to the east of you there is a large hole that looks
as if you might be able to fit through. The roaf continues to the 
north and south.
Endtext
);
set("item_desc", ([
"road" : "Drache Lane. This road runs through the city from north to south. The road itself is packed dirt from many years of use, though it has been unsed in recent years.\n",
"buildings" : "Large buildings that once served as homes and shops for the residents. There is a large hole in the building to the east.\n",
"hole" : "A lrage hole where the door to this building once was. It look big enough to enter.\n",
]));
set("serach_desc", ([
"road" : "You find nothing of interest.\n",
"buildings" : "You find a large gaping hole in the one to the east.\n",
"hole" : "You find a bunch of splinters that you should be careful off when you go through it.\n",
]));
set("exits", ([
"south"  :  "/d/Dark/Duegne/Ruin/town2.c",
"north"  :  "/d/Dark/Duegne/Ruin/town4.c",
"east"   :  "/d/Dark/Duegne/Ruin/house1.c",
]));
::create();
}
