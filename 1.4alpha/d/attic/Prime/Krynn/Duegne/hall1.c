#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A hallway.");
set("long", @Endtext
The hallway is empty except for yourself. There are doors to 
your north and you south. The hallway runs further west towards
more rooms and east to the stairs.
Endtext
);
set("exits" , ([
"west" : "/d/Prime/Krynn/Duegne/hall2.c",
"east" : "/d/Prime/Krynn/Duegne/hall.c",
"south" : "/d/Prime/Krynn/Duegne/innroom1.c",
"north" : "/d/Prime/Krynn/Duegne/innroom2.c",
]));
set("post_exit_func", ([
"south" : "my_exit_func",
"north" : "my_exit_func",
]));
set("item_desc", ([
"hallway" : "The hallway runs east to west amd is lined with doors. The starirs leading down to the common room are to the east.\n",
]));
}
int my_exit_func(){
tell_object(this_player(),"You open the door an enter the room.\n");
tell_room(this_object(),this_player()->query("cap_name") + " just opened the door and entered the room.\n", ({this_player()}));
return 1;
}
