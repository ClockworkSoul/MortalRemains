#include <mudlib.h>
#include "blah.h"

inherit ROOM;

void create() {
object chief;
::create();
seteuid(getuid());

set( "light", 1 );


set("short", "The chief's hut");
set("long", @Sydex
This is the chief's hut.  His hut is the most lavishly
decorated out of the whole village. There are spears and shields 
on the walls.
In the center of the room there is a large chair where the chief
sits. There is and exit to the jungle behind the chair.
Sydex
);
set("exits", ([
"north" : LAND+"path1.c",
"south" : LAND+"village2.c",
]));
chief = clone_object("/d/Outer/Beastlands/Sydex/monsters/chief.c");
chief->move(this_object());
set("item_desc", ([
      "walls" : wrap("lavishly decorated walls.\n"),
      "ground" : wrap("Yup its the ground alright"+
      "hasn't changed much since last time you saw it.\n"),
      "sky" : wrap("You can see the sky, your INSIDE!\n"),
      "vegetation" : "theres none here\n",
      "dirt" : "It is everywhere.\n",
      "path" : wrap("Its a a path that has been well beaten into the ground."+
      "You can tell by lack of vegitation it has been used recently."),
      "sunlight" : "Its beautiful!\n",
    ]) );
}
