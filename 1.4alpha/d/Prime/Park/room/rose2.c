#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A fragrant rose garden");
  set("long", wrap(
"This small garden is filled with white roses, most of which are just buds. "+
"The path winds quite close to the shrubs, and the flowers often stick right "+
"out into the path itself. A soft breeze fills the air with the sweet perfume "+
"of the roses."
     ) );
  set("item_desc", ([
    "small garden" : "The garden is filled with white roses.\n",
    "garden" : "The garden is filled with white roses.\n",
    "white roses" : "Most of the roses are still just buds.\n",
    "roses" : "Most of the roses are still just buds.\n",
    "white rose" : "You stop to admite a delicate white rosebud.\n",
    "rose" : "You stop to admire a delicate white rosebud.\n",
    "buds" : "Most of the roses are still just buds.\n",
    "bud" : "You stop to admire a delicate white rosebud.\n",
    "path" : "The path is paved with stone.\n",
    "flowers" : "Most of the flowers are still just buds.\n",
    "flower" : "You stop to admire a delicate white rosebud.\n",
    ]) );
  set("smell", "The strong scent of the roses is intoxicating.\n");
  set("listen", "You hear birds chirping nearby.\n");
  set("exits", ([
    "northeast" : P_ROOM+"gazebo.c",
    "northwest" : P_ROOM+"rose1.c",
    "southeast" : P_ROOM+"rose3.c",
    ]) );
  set("objects", ([
    "worm": P_MON+"worm.c",
    ]) );
  reset();
  }
