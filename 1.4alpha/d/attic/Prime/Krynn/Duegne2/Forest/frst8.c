#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("objects", ([
"firedrake"  :  "/d/Prime/Krynn/Duegne2/monsters/firedrk.c",
]));
reset();
set("listen", "The forest is deathly quiet here, making you feel very uneasy.\n");
set("outside","Dark");
set("light", 1);
set("short", "Deep within the forest");
set("long", @Endtext
You stand deep inside the forest on what appears to be a dead end
in the path. It is deathly quiet here and you are not quite sure
you want to stick around very much longer.
Endtext
);
set("item_desc", ([
"forest" : "Large trees tower aboce you, allowling very little view into the forest itself.\n",
"trees" : "Large trees cluttered together which make view the inside of the forest difficult.\n",
"path" : "Dirt path leading through the forest.\n",
]));
set("search_desc", ([
"trees" : "They are too dense to search them properly so you give up, finding nothing.\n",
"forest" : "You find nothing but trees.\n",
"path" : "You find nothing but dirt.\n",
]));
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne2/Forest/frst6.c",
]));
::create();
}
