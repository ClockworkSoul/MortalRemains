#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("short", "A forest path");
set("long", @Endtext
You stand on a small dirt path in the forest. Large trees, all of
which seem to be the same kind of tree, tower high above you. The
forest seems a little more peaceful here than it has in other
places. You notice the path runs to the northwest and so the south.
Endtext
);
set("exits", ([
"northwest"  :  "/d/Prime/Krynn/Duegne2/Forest/frst1.c",
"south"  :  "/d/Prime/Krynn/Forest/frst9.c",
]));
set("item_desc", ([
"path"  :  "A small dirt path running through the forest.\n",
"forest"  :  "The forest is full of large trees.\n",
"trees"  :  "The trees here all seem to be of the same breed.\n",
]));
set("search_desc", ([
"forest" : "You search the forest and find.....a bunch of trees. Wow, what a surprise that is huh?\n",
"trees" : "You find a bunch of bark. If you were a dog you would be in heaven here.\n",
"path" : "You find some dirt. How lovely.\n",
]));
}
