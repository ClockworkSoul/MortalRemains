#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("objects", ([
"guard" :  "/d/Prime/Krynn/Duegne2/monsters/bane.c",
]));
reset();
set ("light", 1);
set ("short", "Ancient ruins");
set ("long", @Endtext
The silene in this room is eerie and very disturbing. You are
doing everything in your power to keep under control. The shadows
play tricks with your mind making you feel as if you are being 
watched. Yet when you look around you do not notice anything
out of the ordinary. The wind rustles the dust on the floor, yet
makes no noise that you can here. To the north the corridor contiues
while it also branches off to the east and west here. To the south
is the entrance to the structure and the forest beyond.
Endtext
);
set ("item_desc", ([
"shadows" : "They seem to dance along the walls, giving them an eerie lifelike quality.\n",
"walls" : "Smooth obsidian walls reflecting the light in mysterious ways.\n",
"floor" : "A very smooth yet worn floor below you shaking feet.\n",
"ceiling" : "High and cracked, the wind blows through creating a most unerving howl.\n",
"corridor" : "Dark and very univiting, yuo sense that great evil awaits you down there.\n",
]));
set ("search_desc", ([
"shadows" : "You search the shadows and again find nothing.\n",
"walls" : "You find nothing but smooth stone.\n",
"floor" : "You find nothing.\n",
"ceiling" : "It is too high and dangerous to do that.\n",
"corridor" : "You find nothing but darkness.\n",
]));
set ("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin1.c",
"north"  :  "/d/Prime/Krynn/Duegne2/Ruin/ruin3.c",
"west"   :  "/d/Prime/Krynn/Duegne2/Ruin/ruin5.c",
"east"   :  "/d/Prime/Krynn/Duegne2/Ruin/ruin4.c",
]));
set("pre_exit_func", ([
"north" : "guarded",
"west" : "guarded",
"east" : "guarded",
]));
}
int guarded(){
if (present("baneguard", TO)){
    write("The baneguard says: You shall have to kill me first to proceed.\n");
return 1;
}
return 0;
}
