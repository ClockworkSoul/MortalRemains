#include <mudlib.h>
#include "blah.h"

inherit ROOM;

void create() {

::create();
seteuid(getuid());

set( "light", 1 );


set("short", "A jungle path");
set("long", @Sydex
The path is defenatly thinning out.
Vegetation is getting somewhat sparce.  Insect life is vertualy non existant.
Sydex
);
set("exits", ([
"west" : LAND+"waist5.c",
"east" : LAND+"waist3.c",
]));
set("item_desc", ([
      "ground" : wrap("Yup its the ground alright"+
      "hasn't changed much since last time you saw it."),
      "sky" : wrap("Oh ya! thats that sky all right! "+
      "You know the big blue thing! "+
      "With the sun in it. "),
      "vegetation" : "It's everywhere!.\n",
      "dirt" : "It is everywhere.\n",
      "path" : wrap("Its a a path that has been well beaten into the ground."+
      "You can tell by lack of vegitation it has been used recently."),
      "sunlight" : "Its beautiful!\n",
    ]) );
}
