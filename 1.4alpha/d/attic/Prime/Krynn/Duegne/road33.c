#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Outside morgue.");
set("long",@Endtext
Standing outside the city morgue you can sense and smell the
death that is hanging inside. The morgue is directlt to the west
while the road continue back eat to Main St.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/build27.c",
"east"  :  "/d/Prime/Krynn/Duegne/road32.c",
]));
set("item_desc", ([
"road" : "The cobblestone road runs back to the east towards Main St. while the morgue lies to the west.\n",
"cobblestone" : "Smooth stones that make up the road.\n",
"morgue" : "A large black, oppressive looking building which you can smeel the death eminating from within. You are not sure if you want to enter.\n",
]));
}
