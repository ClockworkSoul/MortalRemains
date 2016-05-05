#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("objects", ([
"crown"  :  "/d/Prime/Krynn/Duegne2/armour/crown.c",
]));
reset();
set("light", 1);
set("short", "Dragon's treasure room");
set("long", @Endtext
Congratualtions mortal. If you have entered this room you have
defeated the evil Takhisis, for she has never let any mortal through
that door while breath still escaped from her lungs. What is in here
you truelly deserve.
Endtext
);
set("item_desc", ([
"room" : "The treasure room of Takhisis, with various gold coins scattered about the floor.n",
]));
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin30.c",
]));
::create();
}
