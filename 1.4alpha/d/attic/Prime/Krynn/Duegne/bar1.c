#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("objects", ([
"bartender" : "/d/Prime/Krynn/mons/bartender.c" ]));
reset();
set("light",1);
set("short", "The bar.");
set("long", @Endtext
The bar is just as crowded as the rest of the inn. There are not
many empty seats and even some of the unoccupied ones are being
used as pillows by some of the drunken patrons. The innkeeper
who also doubles as the bartender tands behind the bar getting
the drinks.
Endtext
);
set("exits", ([
"common" : "/d/Prime/Krynn/Duegne/common.c",
]));
set("item_desc", ([
"bar" : "The bar is a large oaken slab that looks like it was dropped there by some large monster and the inn was built around it. there are all kinds of gouges in the wood.\n",
"gouges" : "They look like they have been made during various sword fights.\n",
"seats" : "Stools used for the patrons to sit upon and for some to hold thenselves up after passing out.\n",
"bartender" : "The innkeeper serves the drinks so as to keep some kind of order at the bar. Most of the time he is successful.\n",
"patrons" : "There are many drunken patrons around the bar.\n",
]));
}
