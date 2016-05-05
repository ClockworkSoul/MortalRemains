#include "/u/d/dalceon/mydefines.h"

inherit ROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Forest Divide");
   set("long", @EndText
You are deep within the forest now.  You jump at every little sound in the 
forest.  You don't know when something is going to jump from out from behind a
tree, or fall from the thick canopy above your head. the forest branches out
into several direction here.  The path to the south leads out. The paths that
lead into the forest are overgrown and hard to see.
EndText
   );

   set("exits", ([
     "east": FOREST+"3.c",
     "northeast": FOREST+"b.c",
     "north": FOREST+"c.c",
     "northwest": FOREST+"d.c",
     "west": FOREST+"e.c",
     "south": FOREST+"2.c"
   ]));
}
