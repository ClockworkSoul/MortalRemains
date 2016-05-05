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
You stand on the west portion of Dragon's Road. To the north is
an entrance to the city's library and to the south is an entrance
to the 'Talisman Tavern'. Just to the east of you is the city 
square which is bustling with activity. Further down the road to
the west is one of the city gates.
Endtext
);
set("exits", ([
"north" : "/d/Prime/Krynn/Duegne/build8.c",
"south" : "/d/Prime/Krynn/Duegne/build3.c",
"west"  : "/d/Prime/Krynn/Duegne/road10.c",
"east"  : "/d/Prime/Krynn/Duegne/square.c",
]));
set("item_desc", ([
"road" : "The road runs west to the gates and east to the square.\n",
"tavern" : "From what you can see from here the tavern is quite busy.\n",
"library" : "A huge building that you imagine must hold countless works.\n",
"gate" : "It is too far down the road for you to clearly see it. All yo ucan make out is the light shiing of its golden gates.\n",
"square" : "All you can make out is a sea of peeople moving about.\n",
]));
}
