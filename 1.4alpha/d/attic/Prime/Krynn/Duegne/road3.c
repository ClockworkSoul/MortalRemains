#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short","Main Street.");
set("long",@Endtext
You stand on Main Street just outside the Dragon's Blood Inn. You
that the Inn is not that packed at all. To your east stands a 
dwelling of some kind. You notice some clothes hanging out of a
second floor window. To the north you notice a lot more activity
as you get closer to the city square. The south leads out of the
city.
Endtext
);
set("exits", ([
"north" : "/d/Prime/Krynn/Duegne/road4.c",
"south" : "/d/Prime/Krynn/Duegne/road2.c",
"west"  : "/d/Prime/Krynn/Duegne/build23.c",
"east"  : "/d/Prime/Krynn/Duegne/build1.c",
]));
set("item_desc", ([
"inn" : "Above the door to the Inn hang a huge sign. The windows are slightly glaxed allowing to see only sillouetes of the figures inside.\n",
"sign" : "A large sign with the picture of a dragon bleeding into a flask.\n",
"windows" : "The windows of the Inn are glaxed not allowing a clear picture of what is inside.\n",
"dwelling" : "it looks to be a plain residence of some kinda.\n",
"clothes" : "The clothes hang from a second floor window. They are too high up to realy make out what kind they are.\n",
"entrance" : "The door looks large enough to fit a small dragon through.\n",
]));
}
