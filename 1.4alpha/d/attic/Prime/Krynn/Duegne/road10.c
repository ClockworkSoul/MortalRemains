#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short","Dragon's Road West.");
set("long",@Endtext
Dragons's Road continue to run west to east here. The town 
square is further down the road to the east and one of the 
city's gates is further down the the west.
Endtext
);
set("exits", ([
"west" : "/d/Prime/Krynn/Duegne/road11.c",
"east" : "/d/Prime/Krynn/Duegne/road5.c",
]));
}
