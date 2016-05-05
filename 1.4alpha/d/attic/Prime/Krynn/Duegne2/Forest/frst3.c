#include <config.h>
#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("outside","Dark");
set("short", "A forest path");
set("long", @Endtext
The forest gives you an eerie feeling with its lack of sound and 
movement. Even the leaves of the trees do not seem to move when the
wind whistles through them. The path here does not look like it
has been used in ages making you wonder just what is in this forest
that has kept travelers out. The path continues to the north and to
the southeast.
Endtext
);
set("item_desc", ([
"path" : "A path running through the forest that has become overgrown with weeds do to its lack of use.\n",
"weeds" : "Small weeds that have grown on the path.\n",
"forest" : "A dense forest that surrounds the path on both sides.n",
"leaves" : "Dark leaves that look almost dead as they hang form the trees.\n",
"trees" : "Various types of trees which tower high above you.\n",
]));
set("search_desc", ([
"path" : "You search the path and find nothing.\n",
"trees" : "You search through the trees and fgind nothing of interest.\n",
"weeds" : "You search the weeds and hope you do not catch poison oak in doing so. You also find nothing amongst the weeds.\n",
"forest" : "You find nothing of interest.\n",
"leaves" : "You search the leaves and find nothing but sying leaves.\n",
]));
set("exits", ([
"southeast"  :  "/d/Prime/Krynn/Duegne2/Forest/frst2.c",
"north"  :  "/d/Prime/Krynn/Duegne2/Forest/frst4.c",
]));
::create();
}
