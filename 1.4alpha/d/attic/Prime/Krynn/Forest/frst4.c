#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("light", 1);
set("short", "Forest path");
set("long", @Endtext
You stand on a small path that runs through the Gar woods. To
your west you can see the edge of the woods with the path leading
to a city in the distance. To your east, the path winds deeper 
into the woods. All around the path are gigantic trees rising
high into the sky, but allowing enough light for you to see.
Endtext
);
set("exits", ([
"west" :  "/d/Prime/Krynn/Forest/frst3.c",
"east" :  "/d/Prime/Krynn/Forest/frst5.c",
]));
set("item_desc", ([
"trees"  :  "Tall, majestic trees rising into the sky.\n",
"path"  :  "A small dirt path running through the woods.\n",
"forest" : "You see trees all around you. What did you expect in a forest? Sand dunes?\n",
]));
}
