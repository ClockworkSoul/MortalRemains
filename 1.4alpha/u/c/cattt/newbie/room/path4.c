#include <newbie.h>

inherit ROOM;

void create(){
   ::create();
   seteuid(getuid());
   set("author","cattt");
   set("light",1);
   set("short","A path in the park.");
   set("long", @End
A path leading through the park.  A few fruit trees trim the path. As
their fruits grow, some have fallen to the ground and become the food
of some of the parks inhabitants.  The path continues to the east to 
a hill while to the northwest the path continues through the park.
End
);
    set("item_desc", ([
      "path":"The path continues to the northwest and the east.\n",
      "trees":"Fruit trees along the path include apples, pears, and "+
              "oranges.\n",
      "fruit":"Half eatting fruit that have fallen off their trees.\n",
      "inhabitants":"You can imagine squirrels and birds as some.\n",
      "hill":"The hill is to the east.\n",
      "park":"The park is extremely beautiful this time of year.\n",
     ]));
    set("smell", "A variety of fruity smells.\n");
    set("exits", ([
        "east": M_ROOM+"hillpath1.c",
        "northwest" : M_ROOM+"path3.c",
     ]));
}
