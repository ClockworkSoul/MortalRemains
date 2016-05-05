#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("outside","Dark");
set("listen", "You hear nothing at all. How very strange.\n");
set("short", "A forest path");
set("long", @Endtext
As you walk through the forest you notice that it is awfuly silent.
All the you hear is the sound of the wind blowing through the trees 
which are all around you, almost seeming to swallow the path into its
midst. You are able to see that the path continues to the east
and south from here.
Endtext
);
set("item_desc", ([
"trees" : "Large trees that tower high above you, alomst swallowing the path.\n",
"path" : "A worn dirt path that leads through the forest.\n",
"forest" : "A large forest made up of many different types of trees.\n",
]));
set("search_desc", ([
"trees" : "You search amongst the trees and almost get lost. You quickly decide to return to the path.\n",
"path" : "You searh the path and find nothing but dirt.\n",
]));
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne2/Forest/frst19.c",
"south"  :  "/d/Prime/Krynn/Duegne2/Forest/frst21.c",
]));
::create();
}
