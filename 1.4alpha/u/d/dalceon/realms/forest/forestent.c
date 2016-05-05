#include "/u/d/dalceon/mydefines.h"

inherit "/u/d/dalceon/myroom.c";

void create()
{
   ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Entrance to Knothole Forest");
   set("long", @EndText
You have just wandered into Knothole Forest.  You hear the sounds of birds and
other forest creatures shuffling around the forest.  The trees stretch for
miles in the air, their tops seem to disappear in the clouds. This path leads
north farther into the forest. You sense that this forest is peaceful and 
quiet, a great place for a new adventurer to go. You could be right, or you 
could be deadly wrong.
EndText
   );

   set("exits", ([
     "north": FOREST+"1.c"
   ]));
}
