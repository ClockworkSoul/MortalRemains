#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("light", 1);
set("short", "A small road");
set("long", @Endtext
You are standing on a small but well used road that leads into
the city of Duegne, which lies to your west. To the east the
road runs into the Gar forest. You really can not make out
much of the forest except it is full of tress. Go figure.
Endtext
);
set("item_desc", ([
"road" : "A small dirt packed road that runs east to the city and west to the forest.\n",
"forest" : "From here all you can make out is that it is full of tres and that the road runs into it.\n",
"city" : "You can make out two huge gates just off to your west.\n",
]));
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/gates3.c",
"east"  :  "/d/Prime/Krynn/Forest/frst2.c",
]));
}
