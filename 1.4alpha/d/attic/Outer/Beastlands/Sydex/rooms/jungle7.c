#include <mudlib.h>
#include "blah.h"

inherit ROOM;

void create() {
object ape;
::create();
seteuid(getuid());

set( "light", 1 );


set("short", "A jungle path");
set("long", @Sydex
It appears that several rabid apes have take up resadence 
here. Watch out. Watch out. The path continues to the north.
Watch out. The path continues to the north.
Sydex
);
set("exits", ([
"north" : LAND+"jungle8.c",
"south" : LAND+"jungle6.c",
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
ape = clone_object("/d/Outer/Beastlands/Sydex/monsters/ape.c");
ape->move(this_object());
}
