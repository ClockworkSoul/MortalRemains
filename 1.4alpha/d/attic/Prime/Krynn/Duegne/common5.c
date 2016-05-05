#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("objects", ([
"brawler"  :  "/d/Prime/Krynn/mons/brawler.c",
"wench"  :  "/d/Prime/Krynn/mons/barwench.c",
]));
reset();
reset();
set("light", 1);
set("short", "The common room.");
set("long", @Endtext
The common room is bustlin with activity. People are ta the bar
drinking and talking about adventures they have had. The tables
are all just about full with people eating and drinking and
grabbing a quick feel from the serving girls. In the corner there
is an entertainer juggling and telling fabulous stories for a good
sized crowd. The innkeeper stands behind the bar serving drinks, 
and to the left of the bar you see a door leading into the kitchen
and a set of stairs leading up to the rooms.
Endtext
);
set("exits", ([
"door"  :  "/d/Prime/Krynn/Duegne/build26.c",
]));
set("item_desc", ([
"bar" : "The bar is crowded with lots of drunk people.\n",
"tables" : "the tables are crowded with a lot of people eatng and drinking.\n",
"kitchen" : "You can not see through the swinging door.\n",
"stairs" : "They look like normal stairs to you.\n",
"keeper" : "The Innkeeper is a large man. You are not sure if you want to mess with him.\n",
"serving maids" : "Pretty girls who prance around half naked serving drinks/ the patrons seem to enjoy it.\n",
"entertainer" : "A very dextrous old man juggling and telling stories. The patrons seem to enjoy this as well.\n",
"people" : "All kinda of people are here.\n",
]));
}
