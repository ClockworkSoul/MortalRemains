
#include <newbie.h>
inherit ROOM;

void create(){
   ::create();

   seteuid(getuid());
   set("author","cattt");
   set("light",1);
   set("short","Entrance to a small park.");
   set("long", @End
A small park extends south of here. From here you can see a hill
off to the southeast and what looks like a playgound to the west.
Large trees are scattered throughout the area.  Bushes and flowers
line the path that guides you through the park.  
End
);
    set("item_desc", ([
      "park" : "A large park full of trees, bushes and other "+
               "greeneries.\n",
      "hill" : "A fairly large hill can be seen to the southest.\n",
      "playground":"From here all you can see is what looks "+
                   "like a good sized play place.\n",
      "trees":"Large and majestic, the trees tower over the area.\n",
      "tree":"There are so many none stand out in particular.\n",
      "bushes":"Green bushes line the path.\n",
      "flowers":"Flower in a variety of colours and sizes.\n",
      "path":"A paved path that winds towards the west.\n",
      "greeneries":"Grass grows long and healthily here.\n",
      "grass":"Bright green and full grass.\n",
    ]));
    set("smell", "The smell of freshly cut grass penetrates you.\n");
    set("exits", ([
        "west" : M_ROOM+"path1.c",
     ]));
}
