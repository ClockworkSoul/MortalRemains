#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "Dragonesti Blvd.");
set("long",@Endtext
Dragonesti Blvd runs westwards off of Main St. To your south
there is an alleyway. You can see some houses down the road to
your east.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road26.c",
"east"  :  "/d/Prime/Krynn/Duegne/road24.c",
"south" :  "/d/Prime/Krynn/Duegne/alley1.c",
]));
set("item_desc", ([
"road" : "The road runs east to west with an alley branching off to the south.\n",
"alley" : "A small alley which lies to your south.\n",
"houses" : "Small dweelingsthat lie to your east off of Dragonesti.\n",
]));
}
