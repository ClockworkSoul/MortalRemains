#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("light", 1);
set("short", "Forest path");
set("long", @Endtext
You stand on a path deep within the Gar woods. The trees tower
above you blockin out almost all the light, but allowing enough
to filter through so that yuo can see. You notice though that the
forest is very quiet and it makes you just a little uneasy.
Endtext
);
set("exits", ([
"northwest"  :  "/d/Prime/Krynn/Forest/frst5.c",
"northeast"  :  "/d/Prime/Krynn/Duegne2/Forest/frst1.c",
]));
set("item_desc", ([
"forest" : "The forest is full of trees. No big surprise there.\n",
"trees" : "The trees tower above you making you feel very small.\n",
]));
}
