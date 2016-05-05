#include <config.h>
#include <mudlib.h>
inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("objects", ([
"guard"  :  "/d/Prime/Krynn/mons/gateguard.c",
"guard1" :  "/d/Prime/Krynn/mons/gateguard.c",
]));
reset();
set("light",1);
set("forbidden", 1);
set("short", "Northern Gates of Duegne");
set("long",@Endtext
Before you lies the gates of Duegne. Each gate has a massive 
dragon engraved upon it symbolizing the ancient power that lies
behind this great city. The road runs south into the city itself
and north towards the forest.
Endtext
);
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne/road36.c",
"north"  :  "/d/Prime/Dagaard/dilligaf/forest/frst43.c",
]));
set("item_desc", ([
"gates" : "Large goledn gates. Perhaps you should look more closely at just one of them to get a better picture.\n",
"gate" : "A large golden gate with a dragon engraced upon its center. Though the gate looks rather ornamenal, you sense that it has more than adequately served its purpose over the centuries.\n",
"road" : "The road becomes cobblestoned as it runs into the city.\n",
"cobblestone" : "Smooth stones which were used to create the road.\n",
"dragon" : "A massive dragon poised to strike its prey.\n",
]));
}
