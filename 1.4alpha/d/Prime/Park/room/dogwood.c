#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A grove of dogwoods");
  set("long", wrap(
"You find yourself in a grove of blossoming dogwood trees. Thick "+
"grass lies beneath you, and birds flutter from tree to tree, chirping "+
"softly. You notice several nests nestled in the trees, filled with "+
"multi-colored eggs."
     ) );
  set("item_desc", ([
    "grove" : "The grove is dense with trees.\n",
    "tree" : "The dogwood tree is covered in blossoms.\n",
    "trees" : "The grove is dense with trees.\n",
    "dogwood" : "The dogwood tree is covered with blossoms.\n",
    "dogwoods" : "The dogwoods are covered with blossoms.\n",
    "dogwood tree" : "The dogwood tree is covered with blossoms.\n",
    "dogwood trees" : "The grove is dense with dogwood trees.\n",
    "thick grass" : "The thick grass is bright green in color and very soft.\n",
    "grass" : "The grass is thick and green.\n",
    "bird" : "Brightly colored birds chirp softly in the trees.\n",
    "birds" : "The trees are filled with brightly colored birds.\n",
    "nest" : "The small nest is filled with eggs.\n",
    "nests" : "Several nests are tucked in the branches.\n",
    "egg" : "The small round egg is bright blue in color.\n",
    "eggs" : "Colorful eggs lie in the nest.\n",
    "multi-colored eggs" : "The eggs are brightly colored.\n",
    ]) );
  set("smell", ([
    "default" : "You inhale and smell the sweet blossoms.\n",
    ]) );
  set("listen", "You hear birds chirping nearby.\n");
  set("exits", ([
    "north" : P_ROOM+"path1.c",
    "west" : P_ROOM+"rose1.c",
    ]) );
  set("objects", ([
    "sparrow" : P_MON+"sparrow.c",
    "skunk" : P_MON+"skunk.c",
    ]) );
  reset();
  }
