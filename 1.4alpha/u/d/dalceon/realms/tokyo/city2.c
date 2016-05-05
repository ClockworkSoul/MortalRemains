#include "/u/d/dalceon/mydefines.h"

inherit MYROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Main Street and First Street");
   set("long", @EndText
You are walking along Main Street. You get an eerie feeling as you
walk along the street.  That same strange black cloud still hangs
over the city.  The tops of the skyscrapers disappear into the cloud.
Broken down cars line the street.  Shattered glass lines the street.
EndText
   );

   set("item_desc", ([
      "cloud" : "A large dark ominous looking cloud. It is very strange.\n"+
                "From here you can see what appears to be a structure.\n",
      "street" : "Main Street. It is lined with skyscrapers. Broken down cars\n"+
                 "and glass fill the street.\n",
      "skyscrapers" : "Towering skyscrapers. All the lights are out. Strange.\n",
      "glass": "Broken glass lining the street.  It comes from the broken car\n"+
               "car windows.\n",
      "windows": "Broken windows on the cars.\n",
      "cars" : "A couple of convertibles, an SUV and a taxi.\n",
      "convertibles" : "A green Cabriolet convertible, and a white Mustang\n"+
                       "convertible.\n",
      "cabriolet" : "A green VW Cabriolet convertible.\n",
      "mustang" : "A white Mustang convertible.  With white leather interior.\n",
      "interior" : "White leather interior of the Mustang.\n",
      "suv" : "A brand new Nissan Pathfinder\n",
      "taxi" : "A yellow Honda Accord taxi.\n",
      "accord": "A yellow Honda Accord being used as a taxi.\n",
  ]) );
   set("exits", ([
     "south": CITY+"1.c",
     "north": CITY+"3.c",
   ]));
}
