#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("objects", ([
"guard"  :  "/d/Prime/Krynn/Duegne2/monsters/dier.c",
"guard2"  :  "/d/Prime/Krynn/Duegne2/monsters/blaze.c",
]));
reset();
set("light", 1);
set("short", "A corridor in the ruins");
set("long", @Endtext
This room seems to be a bit warmer than all the others. You feel
that you are closer to whatever power it is the resides in these
ruins. As you listen closely you think you here something coming
from the room below. The corridor continues to the south and down
Endtext
);
set("item_desc", ([
"corridor" : "The corridor seems to be a bit brighter here and warmer than anywhere else in the ruins.\n",
]));
set("search_desc", ([
"corridor" : "You find nothing.\n"
]));
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin28.c",
"down"   :  "/d/Prime/Krynn/Duegne2/Ruin/ruin30.c",
]));
set("pre_exit_func", ([
"down" : "guarded",
]));
::create();
}
int guarded(){
if (present("guard", TO)){
   write("The guard screams: You shall have to destroy me first!!\n");
if (present("blaze", TO)){
    write("The Blaze moans: I will roast your flesh from your bones before i let you pass!!\n");
return 1;
}
return 0;
}
}
