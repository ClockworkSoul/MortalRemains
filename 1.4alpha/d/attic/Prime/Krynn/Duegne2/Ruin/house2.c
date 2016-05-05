#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "Inner room within the house");
set("long", @Endtext
This seems to be the sleeping quarters for the family. It is a small
room with a single bed against the east wall, and a small dresser 
against the north wall. The walls are bare, without even a window
to look out upon. There are some cloths and other junk strewn about
the room. The door to the west leads back to the main room.
Endtext
);
set("item_desc", ([
"bed" : "A small bed that looks as if it would be very uncomfortable but would serve its purpose.\n",
"dresser" : "A tiny dresser used to store the clothes for the family.\n",
"clothes" : "Some of the families clothes that did not seem to make it into the dresser.\n",
"junk" : "Just some odds and ends strewn about the room.\n",
]));
set("search_desc", ([
"clothes" : "You find nothing but dirty clothes.\n",
"junk" : "You find some junk. What else did you expect to find.\n",
"dresser" : "All you find are some more clothes. Nothing very exciting or important.\n",
"bed" : "You search the bed and and find a small opening underneath it. You think you might be able to fit through it.\n",
]));
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne2/Ruin/house1.c",
"down"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin1.c",
]));
set("exit_suppress", ([
"down"  :  "/d/Dark/Duegne/Ruin/ruin1.c",
]));
::create();
}
