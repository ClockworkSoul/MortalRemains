#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("objects", ([
"citizen"  :  "/d/Prime/Krynn/mons/citizen.c",
]));
reset();
set("light", 1);
set("short", "A dead end.");
set("long",@Endtext
Lubine Way ends rather quickly here in a dead end. Your only
choise is to head back towards Main St.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road21.c",
]));
}
