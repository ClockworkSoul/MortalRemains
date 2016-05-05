#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("outside","Dark");
set("short", "The ancient gates of Duegne");
set("long", @Endtext
You stand before the gates of the ancient city of Duegne. This city
was once bustling with adventures from all over the world, but has
since been leveled to ruins by some mysterious and powerful force.
Standing to either side of the gate are 2 massive stone statues of
dragons. Each one looks as if it is about to pounce on some poor
unfortunate soul. The gate itself is actually two enormous gold doors
that have been sealed open permanently. Legend has it that no army
which intended to raid Duegne ever made it through these gates alive.
The road continues to the north entering the city and to the south
into the forest.
Endtext
);
set("item_desc", ([
"statue" : "Each statue is a massive stone carving of a dragon. They both look very fierce and as if they are about about to attack.\n",
"gate" : "The gate is made of two solid gold doors that seem to be sealed open permanently. You wonder what it would take to close these massive doors.\n",
"road" : "The path turns into a cobblestone road that is very worn here. This road runs through the entire city.\n",
]));
set("search_desc", ([
"road" : "You find nothing but worm cobblestone.\n",
"gates" : "You do not find anything of interest.\n",
"statues" : "You go to search the statues but stop when you think they are watching you move.\n",
]));
set("exits", ([
"north"  :  "/d/Prime/Krynn/Duegne2/Ruin/town1.c",
"south"  :  "/d/Prime/Krynn/Duegne2/Forest/frst7.c",
]));
::create();
}
