#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Peace Street.");
set("long",@Endtext
Peace Street is lined with small houses, which from the looks
of them are owned buy some wealthy people. Peace Street continues
to the east while Main Street lies a little further west.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/road30.c",
"west"  :  "/d/Prime/Krynn/Duegne/road28.c",
"south" :  "/d/Prime/Krynn/Duegne/build20.c",
"north" :  "/d/Prime/Krynn/Duegne/build21.c",
]));
set("item_desc", ([
"road" : "The cobblestone road is lined with houses.\n",
"cobblestone" : "Smooth stones used to make the road.\n",
"houses" : "House that look to be owned by the wealthy.\n",
]));
}
