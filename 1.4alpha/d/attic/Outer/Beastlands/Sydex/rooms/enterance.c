#include <mudlib.h>
#include "blah.h"
inherit ROOM;
void create() {

::create();
seteuid(getuid());

set( "light", 1 );
set("short", "A clearing");
set("long", @Sydex
The landscape changes here. The air has grown hot and wet.
Vegetation hasgrown thick and biting insects have
appeared in great swarms.  Strage animal calls echo from this 
strange land. A primal instinct urges you onward.
Sydex
);
set("exits", ([
"north" : LAND+"jungle.c",
]));
set("item_desc", ([
      "ground" : wrap("Yup its the ground alright"+
      "hasn't changed much since last time you saw it."),
      "sky" : wrap("Oh ya! thats that sky all right! "+
      "You know the big blue thing! "+
      "With the sun in it. "),
      "vegetation" : "It's everywhere!.\n",
      "dirt" : "It is everywhere.\n",
      "ground" : "It is under you, as it should be.\n",
      "path" : wrap("Its a a path that has been well beaten into the ground."+
      "You can tell by lack of vegitation it has been used recently."),
      "sunlight" : "Its beautiful!\n",
    ]) );       
}
