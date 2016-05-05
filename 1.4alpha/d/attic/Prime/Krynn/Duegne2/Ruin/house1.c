#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "Inside an abandoned house");
set("long", @Endtext
You are in what appears to be a bedroom. Although if it was not
You are staning in a small room inside the house. To the east
is what was the bedroom while to the west is the main toom
of the house.
Endtext
);
set("item_desc", ([
"table" : "A small wooden table that looks as if the family who once lived here ate at.\n",
"dishes" : "Stone dishes used to eat of off.\n",
"fireplace" : "A small fireplace that served as both a heat source and a light source from what it seems.\n",
"trinkets" : "Small trinkets and family hierlooms.\n",
]));
set("search_desc", ([
"table" : "You find some dishes scattered about the table.\n",
"dishes" : "Stone dishes that seem to have been molded to the table somehow.\n",
"fireplace" : "You find some ashes, but that is all.\n",
"trinkets" : "Family valuables. Even YOU feel bad about taking any of these things.\n",
]));
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne2/Ruin/house2.c",
"west"  :  "/d/Prime/Krynn/Duegne/build1.c",
]));
::create();
}
