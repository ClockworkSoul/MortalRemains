#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Dead End.");
set("long",@Endtext
Peace Street end suddenly here in a dead end. Main Street lies 
further down the road to your west.
Endtext
);
set("exits", ([
"west" : "/d/Prime/Krynn/Duegne/road29.c",
]));
}
