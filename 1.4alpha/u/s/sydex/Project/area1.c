#include <mudlib.h>
#include "def.h";
inherit ROOM;
void create() {
  ::create();
  seteuid(getuid());







set("light",1);
set("short","A junction");

set("long", @SydeX
This is the other side of the archway. The ground hear is coverd with 
frost and there ar patchs of snow on the ground. The air has a sting 
to it. There are three possible routs. North is what apears to be some
sort of castle. East there apears to be a small village of some kind,
and to the west is the Archway.
SydeX
);


set("exits", ([
    "east" : "HOME/enterance.c",
    "west" : "HOME/village1.c",
    "north": "HOME/castle1.c",
])
);
}
