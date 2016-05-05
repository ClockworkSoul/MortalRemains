#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",1);
set("short","A table.");
set("long",@Endtext
The table is slightly crowded with some adventures taking a 
break from thier adventuring and telling the stories of thier
journeys. Various plates of food are scattered across the table
along with both empty and full mugs of ale. Serving maids rush
about trying to avoid the prying hands of the men, but they do 
not try too hard.
Endtext
);
set("exits", ([
"common"  :  "/d/Prime/Krynn/Duegne/common2.c",
]));
set("item_desc", ([
"table" : "A square wooden table with chairs around it. About three quarters of the chairs are occupied. Food and drink are scattered about the table.\n",
"food" : "Some roast, soup, and bread are scattered about the table in various stages of comsumption.\n",
"drink" : "There seem to be more empty mugs here than full ones. Look slike this party as been happening for awhile.\n",
"plates" : "What the food is on.\n",
"mugs" : "What the ale is being served in.\n",
"maids" : "Serving maids who are bringing the food nd drink and somewhat keeping the men entertained.\n",
"men" : "Men of all race and size sitting around the table. A good portion of them are drunk off their arse.\n",
]));
}
