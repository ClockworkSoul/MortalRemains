#include <config.h>
#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("objects", ([
"firedrake"  :  "/d/Prime/Krynn/Duegne2/monsters/firedrk.c",
]));
reset();
set("light", 1);
set("outside","Dark");
set("listen", "There is no sound coming from the forest. How odd.\n");
set("short", "A forest path");
set("long", @Endtext
The trees seems to be a little taller here as well as thicker.
The wind moves through the trees, blowing branches to and fro, yet 
there is no sound from this. This whole forest kinda makes you wish 
you had stayed home in bed. The path continues to the south and to
northeast.
Endtext
);
set("item_desc", ([
"trees"  :  "Tall, dark trees that give you the creeps.\n",
"path"  :  "A worn path travelling through the forest.\n",
"forest" : "A dense forest made up of a number of large trees.\n",
]));
set("search_desc", ([
"trees"  :  "You find nothing.\n",
"path"  :  "You find nothing.\n",
"forest" : "You find nothing that interests you.\n",
]));
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne2/Forest/frst3.c",
"northeast"  :  "/d/Prime/Krynn/Duegne2/Forest/frst5.c",
]));
::create();
}
