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
"A narrow dirt path winds through the cherry trees in this section of the "+
"park's orchard. The trees are ripe with fruit, and the dark red cherries "+
"look sweet and delicious. You notice several squirrels dashing about, "+
"clutching cherries in their paws."
     ) );
  set("item_desc", ([
    "narrow dirt path" : "The narrow path winds through the orchard.\n",
    "dirt path" : "The narrow path winds through the orchard.\n",
    "path" : "The narrow path winds through the orchard.\n",
    "cherry trees" : "The trees are ripe with fruit.\n",
    "trees" : "The trees are ripe with fruit.\n",
    "cherry tree" : "This tree is ripe with fruit.\n",
    "tree" : "This tree is ripe with fruit.\n",
    "fruit" : "Dark red cherries hang from the trees.\n",
    "dark red cherries" : "Dark red cherries hang from the trees.\n",
    "cherries" : "Dark red cherries hang from the trees.\n",
    "cherry" : "The cherry looks sweet and delicious.\n",
    "squirrels" : "Squirrels scurry from tree to tree.\n",
    "squirrel" : "A small squirrel holds a cherry in its paws.\n",
    "paws" : "The tiny paws hold a ripe cherry.\n",
    ]) );
  set("smell", "The air is thick with the scent of cherries.\n");
  set("listen", "You occassionally hear the sound of the squirrels moving "+
      "about.\n");
  set("exits", ([
    "northwest" : P_ROOM+"pond1.c",
    "southeast" : P_ROOM+"orchard2.c",
    "south" : P_ROOM+"pine.c",
    ]) );
  set("objects", ([
    "squirrel" : P_MON+"squirrel.c",
    "robin" : P_MON+"robin.c",
    ]) );
  reset();
  }
