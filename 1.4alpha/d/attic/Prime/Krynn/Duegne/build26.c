#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short","Dragon's Blood Inn");
set("long",@Endtext
You are standing on the porch of the Dragon's Tear Inn. There
is not much that is going on outside the Inn, but you can hear
a ton of noise coming from inside the Inn. There is a door
here that looks big enough to wheel a dragon through along with
a glazed window.
Endtext
);
set("exits", ([
"north"  :  "/d/Prime/Krynn/Duegne/road9.c",
"door"   :  "/d/Prime/Krynn/Duegne/common4.c",
"window" :  "/d/Prime/Krynn/Duegne/common5.c",
]));
set("post_exit_func", ([
"window" : "my_window_func",
]));
set("item_desc", ([
"porch" : "The small porch has a few items on it but other than that it is empty of anything useful.\n",
"items" : "The is an old brokendown rocking chair and a horse hitch.\n",
"chair" : "This chair is so old that even the bravest adventurer does not dare sit in it.\n",
"hitch" : "The hitch looks like it is used to hitch horses to.\n",
"window" : "A glazed window that is really hard to see thorugh. All you can make out are some shapes from inside the Inn.\n",
"door" : "The door looks wide enough to wheel a dragon though. You will have no problem going through it.\n",
"inn" : "The Dragon's Blood Inn.\n",
]));
}
int my_window_func(){
tell_object(this_player(),"You have just taken 10 points of damage from jumping through the window.\n");
tell_room(this_object(),this_player()->query("cap_name") + " just took " + "10 points of damage from the slashing glass of the window.\n", ({this_player()}));
this_player()->receive_damage(10,"slashing");
return 1;
}
