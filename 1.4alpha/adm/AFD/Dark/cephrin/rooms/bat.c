#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
The battlefield that surrounds you is quite impressive indeed.
Skeletons of all races litter the ground as if in a waste storage
area, they number in the hundreds and perhaps thousands.  Most
of the skeletons are clothed in rusted and decayed armor.  A
flag can be seen on the eastern horizon, a banner in orange in black.
EndDesc);

set("item_desc", ([ "flag" : "It is the ancient flag of the Cephrin city guard.\n",
                 "skeletons" : "Fallen warriors to an unknown cause lie here like garbage.\n",
                 "armor" : "This armor is completely useless, it has rotten beyond use.\n",
                 "flag" : ""+query("item_desc/flag")+"",
]));
set("exits", ([
     "west" : "/d/Dark/Keldros/rithik/rooms/npath5.c",
     "east" : ROOMS(b3),
     "north" : ROOMS(b2),
     "northeast" : ROOMS(b1),
]));

::create();
}