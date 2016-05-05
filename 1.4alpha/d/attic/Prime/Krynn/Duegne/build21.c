#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "A small house");
set("long", @Endtext
This is a small house off of Peace Street. It looks as if 
the person who owns it has a little bit of money. The furniture
looks new and there are some nice paintings hanging on the wall.
It looks clean but rather boring as well.
Endtext
);
set("exits", ([
"south"  :  "/d/Prime/Krynn/Duegne/road29.c",
]));
set("item_desc", ([
"furniture" : "Some nicely decorated chairs and a maching couch and love seat. It looks so quaint that you want to puke.\n",
"paintings"  :  "The paintings seem to depict tranquil loving scenes of peace and harmony. You feel your stomach getting a little queasy form being in here.\n",
]));
}
