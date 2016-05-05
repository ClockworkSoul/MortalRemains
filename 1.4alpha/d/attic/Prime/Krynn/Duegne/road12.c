#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short", "Dragon's Road West.");
set("long",@Endtext
You stand on Dragon's Road West just to the north of the Dragon's
Road Inn. To the west you can make out the ginat city gate. The
road continue to the east as well.
Endtext
);
set("exits", ([
"south" : "/d/Prime/Krynn/Duegne/build25.c",
"west"  : "/d/Prime/Krynn/Duegne/road13.c",
"east"  : "/d/Prime/Krynn/Duegne/road11.c",
]));
set("item_desc", ([
"road" : "The road continue west to ast here, with an inn to the south.\n",
"inn" : "The Dragon's Road Inn. There is a sign hanging about the etrance and a huge windown on the front facade.\n",
"sign" : "The sign is of a sleeping dragon with a cbblestone path running down its back. You think you see a figure pulling a keg cart along the path.\n",
"window" : "The window is to hazy for you to make out anything but shadows from inside the inn.\n",
"shadows" : "The shadows are of figures from inside the inn.\n",
]));
}
