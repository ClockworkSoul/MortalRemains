#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "A dank corridor inside the ruins");
set("long", @Endtext
This corridor is much is just like all the other ones in here with
the exception that it smeels real bad. You are not sure what the
smell is from nor are you sure you want to know. A pile of bones
lies off in the corner making you wonder if that was the last
adventurer who made the mistake of coming in here. Even though you
are deep within the ruins now, there is still plenty of light for
which you to see. The corridor continues to the south and branches
off to the northwest as well.
Endtext
);
set("smell", "This room smells like rotten flesh.\n");
set("item_desc", ([
"bones" : "A pile of bones that lies motionless in the corner.\n",
"walls" : "The walls seem to glow slightly with an unusual light.\n",
"floor" : "The floor is covered with a thin layer of dust, unlike the other clean spots you have noticed.\n",
"ceiling" : "The ceiling is high and seems to be pretty much intact in this room.\n",
"corridor" : "A small corridor deep with the ruins. A pile of bones lies in the corner.\n",
]));
set("search_desc", ([
"bones" : "After searching the bones you realize they are human and quickly back away.\n",
"walls" : "You examine the walls and notice that they are glowing slightly. You wonder, what could make them do that?\n",
"floor" : "You search the floor and find nothing but a thin layer of dust.\n",
"dust" : "You search the dust and it flies up into your nose making you sneeze violently. For your sake I hope no one heard that.\n",
"ceiling" : "It is much to high for you to search.\n",
"corridor" : "You find a pile of bones in the corner and some dust on the floor.\n",
]));
::create();
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin2.c",
"northwest"  :  "/d/Prime/Krynn/Duegne2/ruin/ruin6.c",
]));
}
