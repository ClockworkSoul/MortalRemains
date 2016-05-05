#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Top of the stairs.");
set("long",@Endtext
You stand at the top of the stairs leading down to the common 
room. The hallway runs west and there are some rooms branching
off of it. The hallway itself looks empty.
Endtext
);
set("exits", ([
"stairs" : "/d/Prime/Krynn/Duegne/hallway1.c",
"west"   : "/d/Prime/Krynn/Duegne/hall1.c",
]));
set("item_desc", ([
"stairs" : "Narrow stairs leading down to the common room.\n",
"hallway" : "The hallway look empty. Everyone must be down in the common room.\n",
"rooms" : "You can not see into the rooms as all the doors are closed. The people staying in the inn are not THAT stupid.\n",
]));
}
