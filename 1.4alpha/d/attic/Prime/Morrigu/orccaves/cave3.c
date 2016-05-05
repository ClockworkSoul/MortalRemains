/*File: cave3.c
**Purpose: more of the cave
**Where: in the orccaves
**Why: Why not?
**How: you figure it out
**Last edited: 4/26/98
*/

#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "a cave intersection");
set("long", @FUBAR
The cave seems to split here and head four directions.  You can see
and more importantly smell orcs every way but west of here.  There
are torches on the walls keeping the place light enough to see.
FUBAR
);
set("exits", ([
"west" : "/d/Prime/Morrigu/orccaves/cave2.c",
"east" : "/d/Prime/Morrigu/orccaves/cave4.c",
"north" : "/d/Prime/Morrigu/orccaves/cave9.c",
"south" : "/d/Prime/Morrigu/orccaves/cave19.c",
]));
}
