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
Peace Street eastwards off of Main Street and is lined with
small houses. From the looks of it this is where most of
the wealthier people in Duegne live.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/road28.c",
"west"  :  "/d/Prime/Krynn/Duegne/road18.c",
]));
set("item_desc", ([
"road" : "The coblestone road runs eastwards off of Main Street and is lined with small houses.\n",
"houses" : "Small houses that look like they belong to some of the wealthier residents in town.\n",
"cobbletones" : "Small stones used to make up the road.\n",
]));
}
