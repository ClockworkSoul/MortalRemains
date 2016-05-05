#include "/u/d/dalceon/mydefines.h"

inherit MYROOM;

void create()
{
   ::create();
   seteuid(getuid());
   set("author", "dalceon");
   set("light", 1);
   set("short", "Third and Main");
   set("long", @EndText
You are at the corner of Third and Main, the center of the city.  You
can plainly see a large castle hanging from that large cloud.  You feel
an intense evil in this area.  You know you shouldn't be here, but your
curiosity is getting the best of you.  You see a strange energy
ementating from the top of the castle and spreading throught the city.
EndText
   );

   set("item_desc", ([
      "cloud" :       "A large dark ominous looking cloud. There is a large castle sitting\n"+
                      "in in the center of the cloud.\n",
      "main street" : "Main Street. It is lined with skyscrapers. It heads north out of\n"+
					  "city towards a huge volcano.\n",
      "skyscrapers" : "Towering skyscrapers. All the lights are out. Strange.\n",
      "castle": "A large castle hanging in the cloud.  It appears to be made of solid\n"+
                "gold. It is sort of a triangle, with spires jutting out from each\n"+
                "side. Its a magnificent castle, too bad is pure evil. Something \n"+
                "appears to be flying around the castle. One question..How do you get\n"+
                "up there??\n",
      "spires":  "Large horn shaped spires petruding from the sides of the castle.\n",
      "something": "Its something. Actually its a few somethings.\n",
      "somethings": "More of the someting.\n",
      "street": "Which street?? Main Street or Third Street.\n",
      "third street": "Third Steet heads east into a desert, and west into the city.\n",

  ]) );
   set("exits", ([
     "north": CITY+"6.c",
     "south": CITY+"4.c",
   ]));
}
