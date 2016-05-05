
#include "/u/d/dalceon/mydefines.h"
inherit MYROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Entrance to New Tokyo");
   set("long", @EndText
You have entered the city of New Tokyo.  There is a dark cloud hanging
over the city. An very powerful evil has taken over the city. The
evil has enhanced the evil in the hearts of people. It has turned them
greedy and paranoid. You are currently walking down Main Street. Large
skyscrapers tower above you.
EndText
   );

   set("item_desc", ([
      "cloud" : "A large dark ominous looking cloud. It is very strange.\n",
      "street" : "A long dirty street. Skyscrapers line either side.\n",
      "skyscrapers" : "Towering skyscrapers. All the lights are out. Strange.\n"
   ]) );
   set("exits", ([
     "north": CITY+"1.c"
   ]));
}
