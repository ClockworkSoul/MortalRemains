#include <mudlib.h>
#include "blah.h"

inherit ROOM;

void create() {

::create();
seteuid(getuid());

set( "light", 1 );

set("short", "In a jungle village");
set("long", @Sydex
The small jungle comunity seems centered on
a large hut just to the north.  The village looks as
if it has suffered years of seige
and warfare.
Sydex
);
set("exits", ([
"north" : LAND+"cfhut.c",
"south" : LAND+"village1.c",
]));
set("item_desc", ([
      "huts" : wrap("little brown huts.\n"),
      "ground" : wrap("Yup its the ground alright"+
      "hasn't changed much since last time you saw it.\n"),
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
