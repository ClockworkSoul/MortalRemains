#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("light", 1);
set("short", "Forest path");
set("long", @Endtext
You stand on a path deep within the Gar woods. All around you
trees rise high into the sky. As you look up and down the path
you notice that it is clear, but that is all that you can make out.
You do notice that the forest is very quiet though.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Forest/frst4.c",
"southeast" : "/d/Prime/Krynn/Forest/frst6.c",
]));
set("item_desc", ([
"trees" : "Tall trees ising high into the sky.\n",
"forest" : "You look at the forest and see trees all around you. Wow, trees in a forest. Who would have thunk it?\n",
"path" : "A small dirt path leading through the woods.\n",
]));
}
