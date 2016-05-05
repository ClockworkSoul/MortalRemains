#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create ()
{
::create();
seteuid(getuid());
set("objects", (["librarian" : "/d/Prime/Krynn/mons/librarian.c"]));
reset();
set("light", 1);
set("short", "Library Lobby");
set("long", @Endtext
You have enter the main lobby of the library. There are books
from all over the realm lining the walls. In the middle of the
library there is a desk where the head librarian is located.
You see that there are entrances in the walls leading to smaller
sections of the library. Something is telling you to be very
quiet in here.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/build8.c",
"west"  :  "/d/Prime/Krynn/Duegne/lib1.c",
"south" :  "/d/Prime/Krynn/Duegne/lib2.c",
"north" :  "/d/Prime/Krynn/Duegne/lib3.c",
]));
set("item_desc", ([
"desk" : "A large oaken desk cluttered with many book and papers. Seated at the desk is a woman who looks to be the head librarian. You might not want to disturb her.\n",
"books" : "There are hundreds and hundreeds of books here, lining the walls from floor to ceiling. Some look older than the others but none really appeal to you very much.\n",
"walls" : "The walls are lined with books.\n",
"ceiling" : "Something has to keep the rain off the books. This one does the job nicely.\n",
"floor" : "The floor, like the steps outside, are imaculate. You almost feel like you are violating some kind of sanctuary.\n",
]));
}
