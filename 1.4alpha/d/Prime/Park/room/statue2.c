#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Before an imposing statue");
  set("long", wrap(
"A tall statue dominates this section of the park. Depicting a man on "+
"horseback, it is quite imposing and somber. The man has a stern look on "+
"his face and one arm raised above his head, brandishing a sword. The horse "+
"is rearing up on its hind legs, ready to charge into battle."
     ) );
  set("item_desc", ([
    "tall statue" : "The statue depicts a man on horseback.\n",
    "statue" : "The statue depicts a man on horseback.\n",
    "man" : "The man is brandishing a sword.\n",
    "face" : "The man's face is stern and somber.\n",
    "arm" : "The man's arm is raised above his head.\n",
    "head" : "The man's arm is raised above his head.\n",
    "sword" : "The man wields a large sword.\n",
    "horse" : "The horse is ready to go into battle.\n",
    "hind legs" : "The horse is reared up on its hind legs.\n",
    ]) );
  set("smell", "The scent of flowers drifts in from the nearby gardens.\n");
  set("listen", "You hear birds chirping nearby.\n");
  set("exits", ([
    "north" : P_ROOM+"path5.c",
    ]) );
  set("objects", ([
    "dragonfly" : P_MON+"dragonfly.c",
    "centipede" : P_MON+"centipede.c",
    ]) );
  reset();
  }
