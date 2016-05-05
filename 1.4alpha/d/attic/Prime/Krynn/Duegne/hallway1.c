#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "A stairway.");
set("long",@Endtext
A narrow stairwell conneting the common room and the upper level
of the inner containing the patrons rooms.
Endtext
);
set("exits", ([
"down" : "/d/Prime/Krynn/Duegne/common.c",
"up"   : "/d/Prime/Krynn/Duegne/hall.c",
]));
set("item_desc", ([
"stairs" : "Narrow stairs leading up and down.\n",
]));
}
