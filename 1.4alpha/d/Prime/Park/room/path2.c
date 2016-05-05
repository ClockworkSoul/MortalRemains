#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Along a cobblestone path");
  set("long", wrap(
"Dark green shrubs flank the cobblestone path. The shrubs are small and "+
"neat, allowing you a view over them into the park's gardens. You are "+
"amazed by the variety of flowers and trees that you see in the distance."
     ) );
  set("item_desc", ([
    "dark green shrubs" : "The shrubs are small and neat.\n",
    "shrubs" : "The shrubs are small and neat.\n",
    "green shrubs" : "The shrubs are small and neat.\n",
    "shrub" : "This shrub is very well-manicured.\n",
    "cobblestone path" : "The path is paved with cobblestones.\n",
    "path" : "The path is paved with cobblestones.\n",
    "gardens" : "You can see the gardens in the distance.\n",
    "flowers" : "You see colorful flowers in the distance.\n",
    "trees" : "You see towering trees in the distance.\n",
    ]) );
  set("smell", "The faint scent of flowers drifts in from the gardens.\n");
  set("listen", "You hear birds chirping in the distance.\n");
  set("exits", ([
   "east" : P_ROOM+"path3.c",
   "west" : P_ROOM+"path1.c",
   "north" : P_ROOM+"statue1.c",
   "south" : P_ROOM+"field1.c",
    ]) );
  set("objects", ([
    "ant" : P_MON+"ant.c",
    ]) );
  reset();
  }
