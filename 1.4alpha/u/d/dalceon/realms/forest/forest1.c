#include "/u/d/dalceon/mydefines.h"

inherit MYROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Knothole Forest");
   set("long", @EndText
You are wandering farther into the forest.  Every thing smells so fresh and 
pleasant.  Little birds fly high up in the trees.  You hear a rustling of the
tree tops...something is up there.  The path heads out of the forest to the 
south, and deeper into the forest to the north.
EndText
   );

   set("exits", ([
     "north": FOREST+"2.c",
     "south": FOREST+"ent.c"
   ]));
}
