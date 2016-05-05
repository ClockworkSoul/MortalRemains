#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("light", 1);
set("short", "Forest entrance");
set("long", @Endtext
This is the entrance to the Gar woods. The path that aslo leads
to the city of Duegne, runs clearly through the woods here. The
trees rise high into the sky along both sides of the path. They
are also bunched close together which does not allow you much
of a view into the forest.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Forest/frst4.c",
"west"  :  "/d/Prime/Krynn/Forest/frst2.c",
]));
set("item_desc", ([
"path"  :  "A small dirt path that runs into the heart of the forest.\n",
"trees"  :  "Various kinds of trees rise high into the air on both sides of the path. They are too close together however for you to see anything else in the forest but the path running through them.\n",
"woods"  :  "All you see are trees and the path running through them.\n",
]));
}
