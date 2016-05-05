#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("objects" , ([
"citizen" : "/d/Prime/Krynn/mons/citizen.c",
"citizen1" : "/d/Prime/Krynn/mons/citizen3.c",
"citizen2" : "/d/Prime/Krynn/mons/citizen4.c",
"citizen3" : "/d/Prime/Krynn/mons/citizen2.c",
]));
reset();
set("light",1);
set("short","City square.");
set("long",@Endtext
The city square is a huge place bustling with activity. There are
a number of different races moving around here on all types of
business. There is a large platform in the center of the square,
and a gibet just to the left of it. Dragon's Road intersects with
Main Street here, running in a west-east direction.
Endtext
);
set("exits", ([
"north" : "/d/Prime/Krynn/Duegne/road14.c",
"south" : "/d/Prime/Krynn/Duegne/road4.c",
"west"  : "/d/Prime/Krynn/Duegne/road5.c",
"east"  : "/d/Prime/Krynn/Duegne/road6.c",
]));
set("item_desc", ([
"square" : "The square is large and contains a large platform and a gibet just to the left of it. There are numerous creatures roaming the streets.\n",
"platform" : "The platform is large enough to accomodtae several people at once. It must be used for assemblies or important anouncements.\n",
"gibet" : "A wooden pole with an arm jutting out at the top. The arm holds a rope in place. You sense that this i how they take care of crime in the city.\n",
"road" : "The road forms a cross here. Main Street running north and south while Dragon's Road runs weast to east.\n",
"people" : "There are too many people for you to make out anyone.\n",
"races" : "There are too many races for you to really pick out any particular one to study.\n",
"creatures" : "There are too many for you to get a good look at just one.\n",
]));
}
