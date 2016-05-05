#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A small jail");
set("long", @Endtext
This appears to be a small holding cell for the accused 
prisoners. You begin to wonder what they do with the prisoners
once they are convicted. Hopefully you will never find out.
Endtext
);
set("exits", ([
"door"  :  "/d/Prime/Krynn/Duegne/build12.c",
]));
set("item_desc", ([
"cell" : "A small cell that looks very uncomfortable. Hopefully you will never have to spend any time in here.\n",
]));
}
