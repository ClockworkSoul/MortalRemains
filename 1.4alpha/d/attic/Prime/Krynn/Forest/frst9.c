#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("light", 1);
set("short", "A forest path");
set("long", @Endtext
You are walkin along a path deep within the woods. The trees here
tower above you, their bases as big as houses you have seen in some
cities and towns. You try to see the top of them but you become
dizzy as you stare in the sky. The path continues to the north and 
to the southeast.
Endtext
);
set("exits", ([
"north"  :  "/d/Prime/Krynn/Forest/frst8.c",
"southeast"  :  "/d/Prime/Krynn/Forest/frst10.c",
]));
set("item_desc", ([
"trees"  :  "As you look at the trees you notice that they are all of the same breed. You believe they may be ancient Vallenwoods but you are not quite sure.\n",
"path"  :  "A small dirt path running through the forest.\n",
"forest"  :  "The forest is full of trees.\n",
]));
set("search_desc", ([
"trees"  :  "You search through the trees and realize these may be ancient Vallnwoods. Other then that you do not find anything interesting.\n",
"forest"  : "You search the surrounding forest and find trees, trees, and even more trees. You quickly decide that there is nothing else around but trees and return to the path.\n",
]));
}
