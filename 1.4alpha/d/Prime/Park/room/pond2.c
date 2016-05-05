#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Before a peaceful pond");
  set("long", wrap(
"A lone snake slithers across the pond before you. Large ripples form in its "+
"wake, disrupting the otherwise still water. The shore is covered with smooth "+
"pebbles that range in color from tan to black. The clouds above are "+
"reflected perfectly in the crystalline water."
     ) );
  set("item_desc", ([
    "lone snake" : "The snake is large and black.\n",
    "snake" : "The snake is large and black.\n",
    "pond" : "The pond is clear and still.\n",
    "large ripples" : "The snake causes large ripples to form in the pond.\n",
    "ripples" : "The snake causes large ripples to form in the pond.\n",
    "wake" : "Large ripples form behind the snake.\n",
    "still water" : "The water is clear and still.\n",
    "water" : "The water is clear and still.\n",
    "crystalline water" : "The water is clear and still.\n",
    "shore" : "The shore is covered with pebbles.\n",
    "smooth pebbles" : "Pebbles cover the shore.\n",
    "pebbles" : "Pebbles cover the shore.\n",
    "clouds" : "Fluffy white clouds are reflected in the pond.\n",
    ]) );
  set("smell", "You smell flowers in the nearby gardens.\n");
  set("listen", "You hear birds chirping nearby.\n");
  set("exits", ([
    "north" : P_ROOM+"path10.c",
    "northwest" : P_ROOM+"rose3.c",
    "northeast" : P_ROOM+"lily1.c",
    ]) );
  set("objects", ([
    "snake" : P_MON+"snake.c",
    "spider" : P_MON+"spider.c",
    ]) );
  reset();
  }
