#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A fruitful orchard");
  set("long", wrap(
"Peach trees grow near the winding path in this section of the park's "+
"orchard. Large, round peaches grow on the trees, pulling the branches "+
"down with their weight. The air here is thick with the sweet scent of "+
"fruit."
     ) );
  set("item_desc", ([
    "peach trees" : "The trees are ripe with fruit.\n",
    "trees" : "The trees are ripe with fruit.\n",
    "peach tree" : "This tree is ripe with fruit.\n",
    "tree" : "This tree is ripe with fruit.\n",
    "winding path" : "The path winds through the orchard.\n",
    "path" : "The path winds through the orchard.\n",
    "large round peaches" : "The peaches are fuzzy and ripe.\n",
    "peaches" : "The peaches are fuzzy and ripe.\n",
    "peach" : "This peach is fuzzy and ripe.\n",
    "branches" : "The branches are weighed down by the peaches.\n",
    "branch" : "This branch sags under the weight of the peaches.\n",
    "fruit" : "The peaches are fuzzy and ripe.\n",
    ]) );
  set("smell", "The air is thick and fragrant.\n");
  set("listen", "You hear birds chirping in the distance.\n");
  set("exits", ([
    "northwest" : P_ROOM+"orchard1.c",
    "southeast" : P_ROOM+"orchard3.c",
    "southwest" : P_ROOM+"picnic.c",
    ]) );
  set("objects", ([
    "snake" : P_MON+"snake.c",
    ]) );
  reset();
  }
