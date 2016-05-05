#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "Behind the Inn.");
set("long",@Endtext
A small yard behind the Inn. There is really nothing here to 
speak of. It just looks like a place where the inn workers 
come to relax when they get a break.
Endtext
);
set("exits", ([
"kitchen" : "/d/Prime/Krynn/Duegne/kitchen1.c",
]));
}
