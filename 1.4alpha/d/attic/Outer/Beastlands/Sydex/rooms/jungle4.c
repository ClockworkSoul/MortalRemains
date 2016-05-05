#include <mudlib.h>
#include "blah.h"

inherit ROOM;

void create() {
object zombie;
::create();
seteuid(getuid());

set( "light", 1 );


set("short", "A jungle intersection");
set("long", @Sydex
The path splits in to an intersection here. One path
leads North, the other leads west and one leads back 
south.  There is a small sign here.
Sydex
);
set("exits", ([
"north" : LAND+"jungle5.c",
"west" : LAND+"waist1.c",
"south" : LAND+"jungle3.c",
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
zombie = clone_object("/u/s/sydex/zombie.c");
zombie->move(this_object());
}
