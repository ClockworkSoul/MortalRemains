#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Along a narrow path");
  set("long", wrap(
"The path here is so narrow that you can barely fit. It is paved with loose, "+
"grey gravel, and tall reeds grow on either side. You hear rustling in the "+
"reeds and become nervous about what may be moving inside. In the distance, "+
"you hear the loud squawking of a bird and a shiver goes down your spine."
     ) );
  set("item_desc", ([
    "path" : "The path is very narrow here.\n",
    "grey gravel" : "Small bits of gravel pave the path.\n",
    "gravel" : "Small bits of grey gravel pave the path.\n",
    "tall reeds" : "Tall reeds sway gracefully in the breeze.\n",
    "reeds" : "Tall reeds sway gracefully in the breeze.\n",
    "reed" : "This reed is tall and thin.\n",
    ]) );
  set("smell", "You smell a slight rotten smell coming from nearby.\n");
  set("listen", "You hear rustling in the nearby reeds.\n");
  set("exits", ([
    "north" : P_ROOM+"pond1.c",
    "south" : P_ROOM+"path8.c",
    "west" : P_ROOM+"sycamore.c",
    "east" : P_ROOM+"pine.c",
    ]) );
  set("objects", ([
    "toad" : P_MON+"toad.c",
    "snake" : P_MON+"snake.c",
    ]) );
  reset();
  }
