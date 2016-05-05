#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("objects", ([
"citizen"  :  "/d/Prime/Krynn/mons/citizen2.c",
]));
reset();
set("short", "Main Street.");
set("long",@Endtext
You stand on Main Street outside of the courthouse which is to
the west and a lawyers office to the east. You can get a glimpse
of the city gates to the north of you while the city square is
to your south.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/build12.c",
"east"  :  "/d/Prime/Krynn/Duegne/build11.c",
"south" :  "/d/Prime/Krynn/Duegne/road16.c",
"north" :  "/d/Prime/Krynn/Duegne/road18.c",
]));
set("item_desc", ([
"road"  :  "The road cuts through the city running north and south.\n",
"office"  :  "By the sign on the front of the building you can tell it is the law offices of the city.\n",
"building"  :  "The building looks a little run down and old, making you wonder if these lawyers are any good at what they do.\n",
"sign"  :  "The sign reads: 'Willim, Skruem, and Hardy'.\n",
"courthouse"  :  "You can tell by the plaque on the side of the building that this is the city courthouse.\n",
"side"  :  "The building is a sparkling new structure, with a huge statue of a camel standing at the top of the steps.\n",
"steps"  : "The steps are made of what seems to be marble and shiny brightly.\n",
"plaque"  :  "The plaque reads: 'Municiple Court of Duegne'.\n",
]));
}
