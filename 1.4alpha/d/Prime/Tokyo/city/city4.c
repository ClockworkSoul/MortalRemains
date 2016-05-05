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
You are walking along Main Street.  To the north is the center of town.
Main Street heads south into other parts of town.  The skyscrapers
tower above you, making you feel really small.  The city is looking
worn.  The buildings look as if they are a 1000 years old.  That
strange looking cloud still hangs above the city.  Everytime you look at
the cloud, you get the creeps.
EndText
   );

   set("item_desc", ([
      "cloud" : "A large dark ominous looking cloud. It is very strange.\n"+
                "From here you can see what appears to be a castle.\n",
      "main street" : "Main Street. It is lined with skyscrapers. It heads north into\n"+
					  "center of the city.\n",
      "skyscrapers" : "Towering skyscrapers. All the lights are out. Strange.\n",
      "glass": "Broken glass on the east side of the street.  It comes from\n"+
               "the glass broken out of the jewelry store.\n",
      "store": "A small jewlery store inside one of the skyscrapers. The front\n"+
               "glass is broken out. There is a sign out front.\n",
      "castle": "A large castle hanging in the cloud. It can be seen clearer from\n"+
                "the center of the city.  How did it get up there??\n",
      "buildings": "Skyscrapers and other smaller buildings. The buildings seem\n"+
                   "to be worn way more than they should.\n",
      "smaller buildings": "A few shops and a bank.  They all seem to be really\n"+
                            "worn, eventhough they aren't that old.\n",
      "shops": "A bakery and florist.\n",
      "bakery": "Yokahama Bread and sweets.  There's a big sign out front that says\n"+
                "Due to the big castle in the sky, we are CLOSED.\n",
      "sign": "A sign in front of the bakery. Due to the big castle in the sky, we\n"+
              "are CLOSED.\n",
      "florist":  "A shop with a lot of flowers and plants. It appears to be closed.\n",
      "flowers":  "flowers in the florist shop, they appear to be....dead.\n",
      "plants":  "plants in the florist shop, they appear to be....dead.\n",
  ]) );
   set("exits", ([
     "south": CITY+"3.c",
     "north": CITY+"5.c",
   ]));
}
