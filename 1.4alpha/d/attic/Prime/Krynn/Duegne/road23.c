#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Dragonesti Blvd.");
set("long",@Endtext
Dragonesti Blvd. runs to the west of of Main St. To your north 
lies a small house, and at a quick glance you notice a few more
of them further down the road. Main St. is to your east.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/road16.c",
"west"  :  "/d/Prime/Krynn/Duegne/road24.c",
"north" :  "/d/Prime/Krynn/Duegne/build14.c",
]));
set("item_desc", ([
"road" : "Dragonesti runs westwards off of Main St. It is lined with small houses.\n",
"houses" : "Small houses where you believe some of the residents live.\n",
]));
}
