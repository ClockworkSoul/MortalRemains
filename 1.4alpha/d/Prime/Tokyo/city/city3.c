#include "/u/d/dalceon/mydefines.h"

inherit MYROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Main Street and Second Street");
   set("long", @EndText
You have reached the intersection of Main Street and Second street.
None of the stoplights are working.  On the east side of the street
is a jewelry store. To the west you can see a small forest, and to the
east you see where second street dead ends.  The black cloud still
still hangs over the city.  The city seems to be having a black out.
EndText
   );

   set("item_desc", ([
      "cloud" : "A large dark ominous looking cloud. It is very strange.\n"+
                "From here you can see what appears to be a structure.\n",
      "street": "Which street?? Second or Main\n",
      "main street" : "Main Street. It is lined with skyscrapers. Glass fills the street.\n",
      "skyscrapers" : "Towering skyscrapers. All the lights are out. Strange.\n"+
                      "There is a jewelry store in the bottom of one of them.\n",
      "lights": "All the lights in the skyscrapers are out.\n",
      "glass": "Broken glass on the east side of the street.  It comes from\n"+
               "the glass broken out of the jewelry store.\n",
      "store": "A small jewlery store inside one of the skyscrapers. The front\n"+
               "glass is broken out. There is a sign out front.\n",
      "structure": "From here it looks like a large castle?\n",
      "sign" : "Divine Jewlery. est 1975\n"
  ]) );
   set("exits", ([
     "south": CITY+"2.c",
     "north": CITY+"4.c",
     "east":  SECOND+"e1.c",
     "west": SECOND+"w1.c"
   ]));
}
