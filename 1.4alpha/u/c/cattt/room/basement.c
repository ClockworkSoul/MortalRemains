#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
  seteuid(getuid());
  set("author","cattt");
  set("light", 1);
  set("short", "the basement");
  set("long", wrap(
   "It is dark and musky here in the basement.  In this large room are "+
   "various boxes and other stored junk.  The cement walls and floor "+
   "make this room quite chilly.  "
      ) );
  set("item_desc", ([
   "boxes":"Boxes all taped up with writting on them.\n",
   "junk" : "An old couch and scattered odds and ends.\n",
   "walls" :"Cold drab cement walls keep in this room cold.\n",
   "floor" : "A cement slab floor.\n",
   "cement" : "Dark cold cement lines the basement.\n",
   "writting" : "The boxes are labeled for various rooms in the house.\n",
                  ]) );
  set("exits", ([
     "up" : M_ROOM+"hall2.c",
     "south" : M_ROOM+"basement2.c",
        ]) );
}
