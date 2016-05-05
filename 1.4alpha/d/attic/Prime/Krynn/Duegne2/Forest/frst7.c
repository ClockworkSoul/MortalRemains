#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("outside","Dark");
set("short", "Forest path");
set("long", @Endtext
You stand on a path in the forest. The trees here almost seem
to want to swallow you whole. All you can see is the path leading
to the north and south. Other than that, there is only blackness
inbetween the trees.
Endtext
);
set("item_desc", ([
"road" : "The path widens into a small road as it enters the ancient city. You can still make out the old wheel ruts that line the road.\n",
"trees" : "The trees are still thick to either side though they thin out to the north abit allowing you to see the ancient city gate.\n",
]));
set("search_desc", ([
"trees" : "You find nothing.\n",
"road" : "You do not find anything of interest.\n",
]));
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne2/Forest/frst6.c",
"north"  :  "/d/Prime/Krynn/Duegne2/Forest/frst10.c",
]));
::create();
}
