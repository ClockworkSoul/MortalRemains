/*File: cave2.c
**last edited: 4/26/98
**Note: light level set to -1 for simplicity.
**Other Note: C# */

#include <mudlib.h>
#include <config.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "a dark cave");
set("long", @Buggeroff
It's dark in here, but that's not the worst of it.  It smells like orcs
too.  You do see some light coming from a bit farther in the cave.  You
think you see some torches in there, as well as some moving figures.
Buggeroff
);
set("exits", ([
"west" : "/d/Prime/Morrigu/orccaves/cave1.c",
"east" : "/d/Prime/Morrigu/orccaves/cave3.c"
]));
}
