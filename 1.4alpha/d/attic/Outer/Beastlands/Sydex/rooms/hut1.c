#include <mudlib.h>
#include "blah.h"

inherit ROOM;

void create() {
object villager;
::create();
seteuid(getuid());

set( "light", 1 );


set("short", "A small hut");
set("long", @Sydex

This is a small hut in the jungle community.
It is sparcly decorated. A small fire-pit sits in
the middle of the room.
Sydex
);
set("exits", ([
"east" : LAND+"village1.c",
]));
villager = clone_object("/d/Outer/Beastlands/Sydex/monsters/villager.c");
villager->move(this_object());
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
