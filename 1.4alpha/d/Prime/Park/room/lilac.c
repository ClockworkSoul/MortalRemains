#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Surrounded by lilac bushes");
  set("long", wrap(
"The scent of lilacs almost overpowers you as you enter a small garden "+
"filled with the fragrant bushes. The purple blooms hang in clusters from "+
"the branches of dark green foliage. Bees buzz and flit about from flower "+
"to flower. You notice a small hive hanging from a branch of one of the "+
"bushes and decide to be very careful here."
     ) );
  set("item_desc", ([
    "small garden" : "You are in a garden of lilacs.\n",
    "garden" : "The garden is filled with lilacs.\n",
    "lilacs" : "The lilac bushes are in full bloom.\n",
    "bush" : "The lilac bush is in full bloom.\n",
    "bushes" : "The lilac bushes are in full bloom.\n",
    "purple blooms" : "The delicate blooms hang in clusters.\n",
    "blooms" : "The delicate blooms hang in clusters.\n",
    "clusters" : "The delicate blooms hang in clusters.\n",
    "cluster" : "The delicate blooms hang in clusters.\n",
    "branches" : "The branches hold clusters of blooms.\n",
    "branch" : "A hive hangs from the branch.\n",
    "dark green foliage" : "The leaves are dark and shiny.\n",
    "dark foliage" : "The leaves are dark and shiny.\n",
    "green foliage" : "The leaves are dark and shiny.\n",
    "foliage" : "The leaves are dark and shiny.\n",
    "bees" : "Bees flit from flower to flower.\n",
    "bee" : "The bee is bright yellow and black.\n",
    "flower" : "The flower is pale purple in color.\n",
    "small hive" : "Bees swarm around the hive.\n",
    "hive" : "Bees swarm around the hive.\n",
    ]) );
  set("smell", "The air is thick with the sweet scent of lilacs.\n");
  set("listen", "You hear a buzzing sound emanating from the hive.\n");
  set("exits", ([
    "northwest" : P_ROOM+"veg2.c",
    "south" : P_ROOM+"path3.c",
    "east" : P_ROOM+"path8.c",
    ]) );
  set("objects", ([
    "bee" : P_MON+"bee.c",
  ]) );
  reset();
  }
