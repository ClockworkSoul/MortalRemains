#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A room.");
set("long", @Endtext
You stand in one of the inns rooms. It is a quaint little room
with a bed to your left, a small firplace in the wal opposite
the door and to your right lies a small writing table and a
closet to han clothes. This room looks to belong to one of the
patrons downstairs so you might want to leave before they get 
back.
Endtext
);
set("exits", ([
"south" :  "/d/Prime/Krynn/Duegne/hall2.c",
]));
set("item_desc", ([
"table" : "A small writing table with a ann ink well and pen lieing upon it. There are a few papers scattered accross the top of it.\n",
"ink well" : "a rather non-descript ink well.\n",
"pen" : "A rather non-descript pen.\n",
"papers" : "You shuffle through the papers and find nothing of importance there.\n",
"bed" : "A rather quaint little bed made of oak. It is large enough to fit two people if they sleep close together. The sheets look a little rumpled like whoever slept here did not bother to get into bed but just fell on top of it.\n",
"closet" : "A small closet where the patrons can hang their excess clothes while they stay.\n",
"fireplace" : "A small fireplace that looks like it could supply adequate warmth when in use.\n",
"clothes" : "You open the closet and see a few cloaks, pants, and shirts in there but nothing that looks very vauable so you decide to leave it all there.\n",
]));
}
