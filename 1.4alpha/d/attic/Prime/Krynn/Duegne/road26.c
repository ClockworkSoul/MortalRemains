#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "A dead end.");
set("long",@Endtext
You have come to a dead end. Dragonesti Blvd. runs eastward
towards Main St.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/road25.c",
]));
}
