#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "An attic");
set("long", @Endtext
You are standing in the attic of the house. If you though the
room downstairs was filled with dust, you were mistaken. This
room makes the Jal Pur desert look like a sand box. There is
a small cabinet sitting against the wall but other than that
this room is empty.
Endtext
);
set("exits", ([
"down"  :  "/d/Prime/Krynn/Duegne/build1.c",
]));
set("item_desc", ([
"bed"  :  "The bed is small and very uncomfortable.\n",
"cabinet"  :  "The cabinet is also small and does not look like it fit much stuff at all.\n",
]));
}
