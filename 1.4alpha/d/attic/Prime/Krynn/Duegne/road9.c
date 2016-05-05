#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short","Dragon's Road East.");
set("long",@Endtext
You stand just out side the Dragon's Tear Inn which lies directly
to your south. You can see the golden Eastern Gate rise to your
east and the road continues further west towards the center of
the city.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road8.c",
"east"  :  "/d/Prime/Krynn/Duegne/road35.c",
"south" :  "/d/Prime/Krynn/Duegne/build26.c",
]));
set("item_desc", ([
"inn" : "The inn lies to your south. There is a sign hanging over the door to the inn and a huge window on the front facade.\n",
"sign" : "You see a what appears to be a dragon's eye with a tear falling from it.\n",
"window" : "The window is too murky for you to see in it clearly.\n",
"facade" : "The front of the inn has a entrance and a huge window, which a canopy hang over. Above the conaopy or some of the rooms.\n",
"rooms" : "The rooms are too high up for you to make anything out.\n",
"entrance" : "A rather plain looking entrance.\n",
"road" : "The cobblestone road continues east to west.\n",
"cobblestone" : "Smooth stones that are used to make up the road.\n",
]));
}
