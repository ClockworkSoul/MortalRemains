#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("objects", ([
"firedrake"  :  "/d/Prime/Krynn/Duegne2/monsters/firedrk.c",
]));
reset();
set("listen", "There are no sounds coming from the forest. Even the trees are ominously quiet.\n");
set("outside","Dark");
set("light", 1);
set("short", "Deep in the forest");
set("long", @Endtext
You are deep within the forest of Duegne now. The trees here are 
very close together making it impossible to wander from the path. The
same eerie silence that is present in other parts of the forest is
here as well. The path continues to the north where you think you can
make out the top af what is a large statue of some kind. The path
also continue to the southwest.
Endtext
);
set("item_desc", ([
"trees" : "The trees are very dense here.\n",
"path" : "The path here looks a little more worn than in any other part of the forest.\n",
"forest" : "A thick forest surrounding the path.\n",
"statue" : "You are gonna have to get closer to the statue to make anything out.\n",
]));
set("search_desc", ([
"trees" : "The trees are too dense to really look for anything.\n",
"path" : "Yiou find nothing but some dirt along the path.\n",
"forest" : "The forest is to dense for you to search so you return to the path.\n",
"statue"  :  "You are to far away to search that.\n",
]));
set("exits", ([
"north"  :  "/d/Prime/Krynn/Duegne2/Forest/frst6.c",
"southwest"  :  "/d/Prime/Krynn/Duegne2/Forest/frst4.c",
]));
::create();
}
