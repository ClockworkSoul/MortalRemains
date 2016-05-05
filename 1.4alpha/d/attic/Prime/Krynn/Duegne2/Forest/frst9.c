#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("outside","Dark");
set("short", "Forest oath outside walls");
set("long", @Endtext
The path runs along the town walls. They are tall and strong
making you wonder what could have destroyed this ancient town.
The trees are a little thinner here allowing you to see into the 
forest a bit. The path is hardpacked, making you think that this
was once heavily travled by someone or something. The path continues
to the east and the southwest.
Endtext
);
set("item_desc", ([
"path" : "A small forest path with dirt that has been packed by many years of use.\n",
"walls" : "Tall, strong walls that seem to be made of granite. They tower above you giving you an eerie feeling.\n",
"forest" : "Different variety of trees make up the forest, which lines the path to the south.\n",
]));
set("search_desc", ([
"path" : "You search the dirt and find nothing of value.\n",
"walls" : "You search the walls and notice that there are no seams or cracks, almost as if they are part of the earth.\n",
"forest" : "You search the surrounding area and notice a distinct lack of forest life, making you very uneasy.\n",
]));
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne2/Forest/frst11.c",
"southwest"  :  "/d/Prime/Krynn/Duegne2/Forest/frst6.c",
]));
::create();
}
