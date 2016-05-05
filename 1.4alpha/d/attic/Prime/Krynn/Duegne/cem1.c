#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("short", "A cemetary");
set("long", @Endtext
You stand at the back gate of the cemetary. The tombstones
of the dead seem to stretch for miles. There is a door leading
into the morgue.
Endtext
);
set("exits", ([
"door"  :  "/d/Prime/Krynn/Duegne/build27.c",
]));
set("item_desc", ([
"gates" : "Old black gates that open allowing passage from the cemetary to the morgue.\n",
"tombstones" : "Small and large granite blocks marking the graves of the dead.\n",
]));
}
