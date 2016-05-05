#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("objects", ([
"citizen"  :  "/d/Prime/Krynn/mons/citizen3.c",
"citizen2" :  "/d/Prime/Krynn/mons/citizen2.c",
]));
reset();
set("short", "Main Street.");
set("long",@Endtext
You stand on Main Street just outside the school of the city
which lies to your west and and another warehouse which lies
to your east. Main Street itself continues both north and
south of here.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/build10.c",
"east"  :  "/d/Prime/Krynn/Duegne/build9.c",
"south" :  "/d/Prime/Krynn/Duegne/road14.c",
"north" :  "/d/Prime/Krynn/Duegne/road16.c",
]));
set("item_desc", ([
"school" : "The city school where the children come to learn.\n",
"warehouse" : "An old warehouse used to sotre things.\n",
]));
}
