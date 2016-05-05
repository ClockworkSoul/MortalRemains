#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "City morgue");
set("long", @Endtext
This is the morgue of the city. They store the bodies of the dead
here before burying them in the cemetary. It is very cold and
dreary in here. There is also a rather nasty smell coming from
some of the doors that are in the wall. You wonder how long they
wait before burying the body anyway.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/road33.c",
"door"  :  "/d/Prime/Krynn/Duegne/cem1.c",
]));
set("item_desc", ([
"doors" : "Small doors that line the walls. It looks as if they are some kind of storage compartment for the dead. They appeared to be locked tight not that you would want to open one of them anyway.\n",
]));
}
