#include "/u/d/dalceon/mydefines.h"

inherit MYROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("author", "dalceon");
   set("light", 1);
   set("short", "Main Street");
   set("long", @EndText
You are walking along Main Street. The center of the city is to the
south. Main Street seems to end to the north at the base of a volcano.
Skyscrapers line the street on both sides. There is a huge cloud
hovering over the city. From here you can see a giant structure hanging
over the center of the city to the south.
EndText
   );

   set("item_desc", ([
      "cloud" :       "A large dark ominous looking cloud. There is a large structure sitting\n"+
                      "in in the center of the cloud. If you go to the south, you may be able\n"+
                      "to see it better.\n",
      "main street" : "Main Street. It is lined with skyscrapers. It heads north out of\n"+
					  "city towards a huge volcano.\n",
      "street" : "Main Street. It is lined with skyscrapers. It heads north out of\n"+
					  "city towards a huge volcano.\n",
      "skyscrapers" : "Towering skyscrapers. All the lights are out. Strange.\n",
      "structure": "A large structure hanging in the cloud. Whatever it is, it is huge.\n",
      "volcano" :  "A large volcano.  Its giant size makes the city seem small. Its top is\n"+
      			   "obscured by clouds.\n",
      "clouds" :   "Thin grey clouds that are hide the top of the volcano.\n",
      "top" :  "Did I tell you it was obscured by clouds?? YOU CAN'T SEE IT!!\n",

  ]) );
   set("exits", ([
     "south": CITY+"5.c",
     "north": CITY+"7.c",
   ]));
}
