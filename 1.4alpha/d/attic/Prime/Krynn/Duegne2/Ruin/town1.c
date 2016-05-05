#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "Drache Lane");
set("long", @Endtext
You stand on the outskirts of the town, or what is left of it, on
Drache Lane. Small little houses line road on each side, all of them
look as if they have not been inhabited in ages. Down the road and 
to the north you see what appears to be the town square and a large
pile of some kind. You are unable to make out what it is from here
but you know whatever it is, it is massive. The road continues to 
your north and to your south is the town gate.
Endtext
);
set("item_desc", ([
"houses" : "Small dwellings once used by the people who inhabited this town. They have long since been left to rot where they stand.\n",
"road" : "A cobblestone road that runs north/south through the town.\n",
"pile" : "The pile is much to far ahead of you to make anything out of it.\n",
]));
set("search_desc", ([
"road" : "You find nothing of interest here.\n",
"houses" : "As yo ugo to search one of the houses the front porch begins to colapse under your wieght. You decide that it would be best to stay out of these houses.\n",
]));
set("exits", ([
"south"  :  "/d/Dark/Duegne/Forest/frst10.c",
"north"  :  "/d/Dark/Duegne/Ruin/town2.c",
]));
::create();
}
