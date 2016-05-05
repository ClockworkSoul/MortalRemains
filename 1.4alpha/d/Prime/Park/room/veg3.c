#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A bountiful garden");
  set("long", wrap(
"A narrow dirt path winds through rows of root vegetables, including "+
"carrots, turnips, potatoes, and radishes. A bunny sits in the distance, "+
"intent on pulling up a carrot for a snack. You look past this garden "+
"and see brightly colored flowers blooming in the rest of the park."
     ) );
  set("item_desc", ([
    "narrow dirt path" : "The path is surrounded by rows of root vegetables.\n",
    "dirt path" : "The path is surrounded by rows of root vegetables.\n",
    "path" : "The path is surrounded by rows of root vegetables.\n",
    "rows" : "Rows of root vegetables flank the path.\n",
    "root vegetables" : "Rows of root vegetables flank the path.\n",
    "vegetables" : "Rows of root vegetables flank the path.\n",
    "carrots" : "Rows of carrots grow near the path.\n",
    "turnips" : "Rows of turnips grow near the path.\n",
    "potatoes" : "Rows of potatoes grow near the path.\n",
    "radishes" : "Rows of radishes grow near the path.\n",
    "bunny" : "A bunny works hard, trying to pull up a carrot.\n",
    "flowers" : "Flowers bloom in nearby gardens.\n",
    ]) );
  set("smell", "You smell flowers in nearby gardens.\n");
  set("listen", "You hear the bunny moving about in the garden.\n");
  set("exits", ([
    "southwest" : P_ROOM+"veg2.c",
    "south" : P_ROOM+"sycamore.c",
    "northeast" : P_ROOM+"pond1.c",
    ]) );
  set("objects", ([
    "bunny" : P_MON+"bunny.c",
    "ladybug" : P_MON+"ladybug.c",
    ]) );
  reset();
  }
