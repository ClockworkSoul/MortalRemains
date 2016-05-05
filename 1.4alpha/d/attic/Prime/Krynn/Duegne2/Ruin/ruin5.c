#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "A hallway");
set("long", @Endtext
The hallways gives you that same eerie feeling that you are being
watched that you have had throughout the ruins. As is the case 
everywhere, the walls seem to glow with an unnatural light, allowing
you to be able to see. To the west lies the main corridor, while to
the east lies a small small room.
Endtext
);
set("item_desc", ([
"walls" : "Smooth walls that glow by some unknown force.\n",
]));
set("search_desc", ([
"walls" : "You find nothing of use or value.\n",
]));
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin16.c",
"east"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin2.c",
]));
::create();
}
