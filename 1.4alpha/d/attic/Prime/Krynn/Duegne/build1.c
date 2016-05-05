#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A living area");
set("long", @Endtext
You have entered what looks like some kind of living area. Or
what used to be a living area. The layers and layers of dust
give you the impressions that nothing has lived here in a long
time. The room is bare expect for a small table in the corner
next to a fireplace. There is a set of stairs that leads to
another level of the house and a doorway to the east that leads
into another room.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road3.c",
"up"    :  "/d/Prime/Krynn/Duegne/upstairs.c",
"east"  :  "/d/Prime/Krynn/Duegne2/Ruin/house1.c",
]));
set("item_desc", ([
"table"  :  "A small table that looks like it was used for eating by whomever lived here in the past. There are some old dishes and utensils still on the table.\n",
"dishes"  :  "Old stoneware dishes that are layerd in dust.\n",
"utensils" :  "The untensils are quiet old and covered in dust.\n",
"fireplace" : "A small fireplace that looks as if it was used for both heating and cooking.\n",
]));
}
