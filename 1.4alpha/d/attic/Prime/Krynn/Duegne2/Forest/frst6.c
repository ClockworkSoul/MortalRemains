#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("listen", "An uneasy quiet permeats the forest.\n");
set("outside","Dark");
set("light", 1);
set("short", "forest crossroads");
set("long", @Endtext
You have come to a crossroads of sorts in the forest. The trees here
do not look as dense compared to other parts of the path. The same
eerie silence is still here, making you wonder which direction might
be the wisest choice to take. The path continues to the north and 
south as well as the the west and northeast.
Endtext
);
set("item_desc", ([
"path" : "The path splits here into four different directions. Other than that it looks like the same path you have been travelling.\n",
"trees" : "The here are not as clumped together but still look dark and ominous.\n",
"crossroads" : "The path splits here into four different directions.\n",
]));
set("search_desc", ([
"path" : "You do not find anything.\n",
"trees" : "You do not find anything.\n",
"crossroads" : "You find nothing put a path splitting into four directions.\n",
]));
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne2/Forest/frst5.c",
"north"  :  "/d/Prime/Krynn/Duegne2/Forest/frst7.c",
"west"  :  "/d/Prime/Krynn/Duegne2/Forest/frst8.c",
"northeast"  :  "/d/Prime/Krynn/Duegne2/Forest/frst9.c",
]));
::create();
}
