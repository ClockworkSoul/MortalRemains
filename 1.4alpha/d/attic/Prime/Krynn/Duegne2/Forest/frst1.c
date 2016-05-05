#include <config.h>
#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("outside","Darl");
set("short", "A forest path");
set("long", @Endtext
You have come to a fork in road running through the forest. There 
is a sign here with what seems like it has some arrows and writing
on it. Maybe you should examine it.
Endtext
);
set("item_desc", ([
"sign" : "You examine the sign and realize it is in an ancient language that you can barely understand. You are able to make out something about a castle to the east and a town to the southeast as well as another town to the west.\n",
"trees" : "Large trees that tower around you.\n",
"fork" : "The road forks here, splitting into two directions. There is a sign which may tell you were each road leads.\n",
"road" : "The road looks worn from many years of use.\n",
"forest" : "The forest is thick and full of many large towering trees.\n",
"arrows" : "Arrows on a sign pointing in the direction of the roads.\n",
]));
set("search_desc", ([
"trees" : "You find nothing but branches and leaves. What else did you expect to find with trees?\n",
"forest" : "You search the forest and find nothing but trees.\n",
"road" : "You find nothing of interest.\n",
]));
set("exits", ([
"northwest"  :  "/d/Prime/Krynn/Duegne2/Forest/frst2.c",
"southwest"  :  "/d/Prime/Krynn/Forest/frst6.c",
"east"  :  "/d/Prime/Krynn/Forest/frst7.c",
"southeast"  :  "/d/Prime/Krynn/Forest/frst8.c",
]));
::create();
}
