#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("objects", ([
"dragon" : "/d/Prime/Krynn/Duegne2/monsters/shadow_dragon.c",
]));
reset();
set("light", 1);
set("short", "The lair of the Shadow Dragon Takhisis");
set("long", @Endtext
This is the lair of the legendary Takhisis. She is rumored to be
one of the most powerful beasts in all the land, though no one has
returned alive to tell of her power. The lair is huge to accomodate
the enormous size of the beast. Its walls are made of the same 
material as the upper levels, those allowing for you too see well
enough to know that you do not want to be here. You see an opening
through the dragons feet and notice a door way behind her. This must
lead to the dragons treasure. Are you brave enough to attempt to 
take the treasure? Only one way to find out.
Endtext
);
set("item_desc", ([
"walls" : "The walls are made from the same material as throughout the ruins, glowing by some unknown source.\n",
"floor" : "The floor is cluttered with various debris, some of which reminds you of human remains.\n",
]));
set("search_desc", ([
"debris" : "You find the remains of many a slain warrior. You do not want to desecrate their final resting place.\n",
]));
set("exits", ([
"north" :  "/d/Prime/Krynn/Duegne2/Ruin/ruin31.c",
"up"    :  "/d/Prime/Krynn/Duegne2/Ruin/ruin29.c",
]));
set("pre_exit_func", ([
"north" : "guarded",
]));
::create();
}
int guarded(){
if(present("dragon",TO)){
    write("The dragon bellows: None shall pass while I still live.\n");
return 1;
}
return 0;
}
