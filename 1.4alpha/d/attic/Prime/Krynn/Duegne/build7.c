#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A warehouse.");
set("long", @Endtext
You stand in a huge warehouse. There are numerous boxes and 
crates with what seems like eons of dust piled upon them.
You are not sure anyone remembers that this place is here, let
alone what is stored in it.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road14.c",
]));
set("item_desc", ([
"crates"  :  "Very old crates with a lot of dust. You do not think that they are even worth searching.\n",
"boxes"  :  "Very old boxes that yuo do not think are even worth searching.\n",
]));
}
