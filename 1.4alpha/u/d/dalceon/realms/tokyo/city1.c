#include "/u/d/dalceon/mydefines.h"

inherit MYROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Main Street and First Street");
   set("long", @EndText
You are at the intersection of Main Street and First Street. First
street runs to the east and west. To the east is the ocean, and to
the west it runs into a dead end. You still notice the strange cloud
that hangs over the city.  Skyscrapers line the street from the north.
EndText
   );

   set("item_desc", ([
      "cloud" : "A large dark ominous looking cloud. It is very strange.\n",
      "street" : "Which street?? First Street or Main street\n",
      "skyscrapers" : "Towering skyscrapers. All the lights are out. Strange.\n",
      "first street": "First Street runs east to the ocean, and west to a dead end.\n",
      "main street": "Main Street runs north into the city, and south out.\n",

   ]) );
   set("exits", ([
     "south": CITY+"ent.c",
     "north": CITY+"2.c",
     "east" : FIRST+"e1.c",
     "west" : FIRST+"w1.c",
   ]));
}
