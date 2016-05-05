#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("objects", ([
"guard"  :  "/d/Prime/Krynn/mons/gateguard.c",
"guard1"  :  "/d/Prime/Krynn/mons/gateguard.c",
]));
reset();
set("light",1);
set("forbidden", 1);
set("short","Southern Gates of Duegne.");
set("long",@Endtext
Before you stands the gates to the ancient city of Duegne. Built
ages ago by some unknown race, its walls have withstood countless
foes. The gates themsleves are huge golden blocks, each with
an engraved dragon, and from the looks of them they are quite
heavy.
Endtext
);
set("exits",([
"south" : "/d/Prime/Krynn/Forest/frstend.c",
"north" : "/d/Prime/Krynn/Duegne/road1.c",
]));
set("item_desc",([
"gates" : "Two huge golden gates used to bar entance into the city in times of crisis.\n",
"gate" : "A huge gate made entirely of gold and engraved with a dragon. Though rather ornamental looking, you can tell it served its purpose.\n",
"walls" : "The walls are made of some unknown smooth stone that looks unblemeshed over the ages.\n",
]));
}
