#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create(){
::create();
seteuid(getuid());
set("light", 1);
set("short", "A small path");
set("long", @Endtext
This is a small path that leads through the Gar woods. The path
seems to be well worn thourgh lots of travel. To the west lies
the city of Duegne.
Endtext
);
set("exits", ([
"west"  :  "/d/Prime/Krynn/Forest/frst1.c",
"east"  :  "/d/Prime/Krynn/Forest/frst3.c",
]));
set("item_desc", ([
"path"  :  "A small, well travled path that leads east into a froest and west into a city.\n",
"forest"  : "The forest looks inviting enough. Inviting you into what is the question though.\n",
]));
}
