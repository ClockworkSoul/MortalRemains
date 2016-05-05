#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "Municiple Court of Duegne");
set("long", @Endtext
You have entered the Municiple Court of Duegne. This is where
the the rules and judgements of the land are handed down. There
is limited seating in here for viewing any proceddings. There
are two small tables positioned in front of a large podium where
it looks like the judge sits during trials. On the back wall
there is a picture of a large dragon on the left nad side and 
what appears to be a lrage camel on the right. There is also a 
door that leads into a back room.
Endtext
);
set("exits", ([
"east"  :  "/d/Prime/Krynn/Duegne/road17.c",
"door"  :  "/d/Prime/Krynn/Duegne/jail1.c",
]));
set("item_desc", ([
"seats" : "Small wodden benches hwere spectators can sit and watch the trials.\n",
"tables" : "Two small tables where it looks like the lawyers and the accused sit during the trial.\n",
"podium" : "A large sqaure posium raised about 5 feet in the air allowing the judge to look down upon thwe people in his court. Behind the podium are the dragon and camel picture.\n",
"picture" :  "Which one?.\n",
"left picture" : "The picture on the left is what apperas to be a huge dragon descending upon its prey.\n",
"right picture" : "The picture on the right is waht appears to be a camel kicking back and enjoying a cigarette. Kinda odd for a courtroom don't you think?\n",
]));
}
