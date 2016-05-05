#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "Book shelves.");
set("long", @Endtext
One of the smaller sections of the library where people come to
read through the books they find. You try to be very quiet as
there are a few people reading here now.
Endtext
);
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne/libmain.c",
]));
set("item_desc", ([
"shelves"  :  "The shelves contain numeroud books. Since you do not have a library card you can not take any of them.\n",
"books"  :  "Things that you read dumbass.\n",
"people"  :  "They are sitting and reading. Don;t you wish you knew how to do that?\n",
]));
}
