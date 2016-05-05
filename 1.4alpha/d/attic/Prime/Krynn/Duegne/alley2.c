#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "An alley.");
set("long", @Endtext
The alley is filled with all kinds of garbage and debris. The
smell in almost unbearable. The alley continues to the south
while Dragonesti is further to your north.
Endtext
);
set("exits", ([
"enter"  :  "/d/Prime/Krynn/Duegne/sewer1.c",
"north"  :  "/d/Prime/Krynn/Duegne/alley1.c",
]));
set("exit_suppress", ({"enter"}));
set("item_desc", ([
"garbage" : "As you look through the garbage you think you see some kinda of opening in the road.\n",
"opening" : "As you look at the opening it looks as if you could enter it.\n",
"debris" : "The debris is everywhere. There is just too much to look at at once.\n",
"alley" : "The alley is cluttered with garbage and debris.\n",
]));
}
