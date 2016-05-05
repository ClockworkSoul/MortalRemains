#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("short", "Law offices");
set("long", @Endtext
These are the law offices of Willim, Skruem, and Hardy. It
looks a little cleaner inside than the outised, but not by
much. There are some desks, chairs, and filing cabinetes
throughout the room along with a large picture on the back wall.
The only exit is out the way you came in.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road17.c",
]));
set("item_desc", ([
"desks" : "These desk are rather small and cluttered. They do not look organized at all.\n",
"chairs" : "The chairs look old and rickety. I would not sit in one if I was you.\n",
"cabinets" : "The filing cabinets have so much dust on them you wonder if they have ever been used.\n",
"picture" : "The picture is of a relaxing camel with a cigarette in one paw and a small cup of some hot liquid in the other paw. This appears to be the symbol of law in Duegne.\n",
]));
}
