#include <mudlib.h>
#include "blah.h"

inherit ROOM;

void create() {
::create();
seteuid(getuid());

set( "light", 1 );


set("short", "A jungle path");
set("long", @Sydex


The path is wider then ever here. The jungle around
the path is very dence.  Far off in the north you
think you can see some small brown huts.
Sydex
);
set("exits", ([
"north" : LAND+"jungle6.c",
"south" : LAND+"jungle4.c",
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
