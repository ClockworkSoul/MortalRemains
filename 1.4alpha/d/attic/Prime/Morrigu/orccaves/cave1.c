/*Entrance to the orc caves
**created 3/28 by Morrigu
**Light level is set to 1 for
**simplicity at this point. */

#include <mudlib.h>

inherit ROOM;

void create()
{

::create();
seteuid(getuid());
set("objects" , ([
"grunt" : "/d/Prime/Morrigu/orccaves/orcgrunt.c", 
"grunt2" : "/d/Prime/Morrigu/orccaves/orcgrunt.c"
]));
reset();
set("light", 1);
set("short", "cave entrance");
set("long", @Boo
The entrance to this cave seems natural enough, but it sure does smell
bad.  Whatever is making its home in here doesn't know the meaning of
the word "clean".
Boo
);
set("exits", ([
"out" : "/u/m/morrigu/workroom.c",
"east" : "/d/Prime/Morrigu/orccaves/cave2.c"

]));
}
