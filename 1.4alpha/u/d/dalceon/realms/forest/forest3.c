#include "/u/d/dalceon/mydefines.h"

inherit ROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Knothole Forest");
   set("long", @EndText
This side of the forest seems quite peaceful. Nature is in harmony.  The forest
is alive with vegetation.  The trees are tall and strong. The bushes are plush
and fruitful.  There are tracks all over the ground from creatures that have
been forraging here.
EndText
   );

   set("exits", ([
     "north": FOREST+"3a.c",
     "south": FOREST+"3b.c",
     "east": FOREST+"3c.c"
   ]));
}
