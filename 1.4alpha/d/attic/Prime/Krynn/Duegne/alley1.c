#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "An alley.");
set("long",@Endtext
The alley runs south of of Dragonesti Blvd. and is a small
tight squeeze. There is trash and debris scattered everywhere
and the alley is no where near as clean as the main roads. The
alley continues south while Dragonesti lies to your north.
Endtext
);
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne/alley2.c",
"north"  :  "/d/Prime/Krynn/Duegne/road25.c",
]));
set("item_desc", ([
"garbage" : "Disgusting garbage is strewn all over the street.\n",
"debris" : "The debris clutters the street and makes it difficult to walk.\n",
"alley" : "The alley is filled with garbage and debirs.\n",
"trash" : "The trash is everywjere in the alley.\n",
]));
}
