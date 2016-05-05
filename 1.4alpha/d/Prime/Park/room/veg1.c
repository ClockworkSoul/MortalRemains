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
"A narrow dirt path cuts through the center of the park's vegetable garden. "+
"This section of the garden is devoted to growing tomatoes, which hang ripe "+
"and red from the bushes. A bright green snake slithers in the distance, and "+
"birds circle overhead."
     ) );
  set("item_desc", ([
    "dirt path" : "The dirt path is quite narrow.\n",
    "path" : "The dirt path is quite narrow.\n",
    "vegetable garden" : "The vegetable garden is green and vast.\n",
    "garden" : "The vegetable garden is green and vast.\n",
    "tomatoes" : "The tomatoes are round and red.\n",
    "tomato" : "This tomato is round and red.\n",
    "bushes" : "The bushes are tall and green.\n",
    "bush" : "This bush is tall and green.\n",
    "birds" : "Small birds fly overhead.\n",
    "bird" : "Small birds fly overhead.\n",
    ]) );
  set("smell", "The scent of the tomatoes makes your mouth water.\n");
  set("listen", "You hear birds chirping overhead.\n");
  set("exits", ([
    "southwest" : P_ROOM+"enter.c",
    "east" : P_ROOM+"magnolia.c",
    "northeast" : P_ROOM+"veg2.c",
    ]) );
  set("objects", ([
    "snake" : P_MON+"snake.c",
    "crow" : P_MON+"crow.c",
    "skunk" : P_MON+"skunk.c",
    ]) );
  reset();
  }
