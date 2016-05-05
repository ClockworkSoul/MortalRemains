#include <newbie.h>

inherit ROOM;

void create(){
   ::create();
   seteuid(getuid());
   set("author","cattt");
   set("light",1);
   set("short","Just outside a playground.");
   set("long", @End
A playground is right off the path here. The path continues through
the park. 
End
);
    set("item_desc", ([
      "path":"The path continues to the south.\n",
      "playground":"Don't you just want to go play in it?\n",
      "park":"The park is extremely beautiful this time of year.\n",
     ]));
    set("smell", "The airy park smells alive.\n");
    set("exits", ([
        "enter": M_ROOM+"playground.c",
        "east" : M_ROOM+"path1.c",
        "south": M_ROOM+"path3.c",
     ]));
}
