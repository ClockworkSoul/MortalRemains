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
set("short","Eastern Gates of Duegne");
set("long",@Endtext
Here stands the Eastern gates of Duegne. Both gates are made of
solid gold and adhorned with an engraved dragon. To the west lies
the beginning of Dragon's Road which runs through the city from
east to west. To the east you see the beginning of the Gar woods.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road35.c",
"east"  :  "/d/Prime/Krynn/Forest/frst1.c",
]));
set("item_desc", ([
"gates" : "The gaes are an impressive structure and though rather ornamental looking, you know they could serve their purpose well.\n",
"gate" : "The gate is made entirely out of gold and in engraved with a dragon in the center of it.\n",
"road" : "The cobblestone road runs west into the city and east to the forest path.\n",
"path" : "From here the path looks to be packed dirt but it is hard to tell.\n",
]));
}
