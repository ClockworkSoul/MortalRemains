#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 0);
set("short", "An attic.");
set("long", @Endtext
A small cramped attic space. You can barely fit up in here
and even then there is not that much room to move around.
There is so much dust on the floor that you doubt anyone has
been up here in years.
Endtext
);
set("exits", ([
"down"  :  "/d/Prime/Krynn/Duegne/hall4.c",
]));
set("item_desc", ([
"floor" : "There is so much dust on the floor that you can not make anything else out.\n",
"dust" : "It looks like there is at least ten years of dust in this attic.\n",
]));
}
