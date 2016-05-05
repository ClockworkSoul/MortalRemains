#include <newbie.h>

inherit ROOM;

void create(){
   ::create();
   seteuid(getuid());
   set("author","cattt");
   set("light",1);
   set("short","Along the path.");
   set("long", @End
As you travel along the path, the flowers that line it bloom in a vast
variety of colours and shapes.  A bench is here next to a birdbath 
pedestal that is full of water.  A hill is off in the distance to the 
southeast but that is excactly where this path is taking you. A playground 
can be seen to the north.
End
);
    set("item_desc", ([
      "path":"The path continues to the north and the southeast.\n",
      "playground":"A large playground is to the north.\n",
      "flowers":"Many flowers in bloom. Check out those colours!\n",
      "colours":"Blues, reds, yellows, and whites shower the flowers.\n",
      "shapes":"The shapes of roses, tulips, wildflowers and others.\n",
      "bench":"The iron bench doesn't look too comfy but is practical.\n",
      "birdbath":"A stone birdbath filled with water.\n",
      "pedestal":"Made of stone and looks to be sturdy.\n",
      "water":"The water looks fresh and clean, just like the park.\n",
      "hill":"The hill is to the southeast.\n",
      "roses":"     @}-,-'--,---- \nIsn't it pretty.\n",
      "park":"The park is extremely beautiful this time of year.\n",
     ]));
    set("smell", "The airy park smells alive.\n");
    set("exits", ([
        "north": M_ROOM+"path2.c",
        "southeast" : M_ROOM+"path4.c",
     ]));
}
