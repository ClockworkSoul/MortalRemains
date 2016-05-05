#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Along a tree-lined path");
  set("long", wrap(
"Red-bud trees line a winding stone path in this area. The buds are just "+
"beginning to bloom, coloring the trees with their bright petals. Fallen buds "+
"lie on the path, tinting the stone a dark pink. You hear soft chirping "+
"coming from a nearby tree."
     ) );
  set("item_desc", ([
    "red-bud trees" : "The trees are just beginning to bloom.\n",
    "trees" : "The trees are just beginning to blooms.\n",
    "tree" : "This tree is bright red with blossoms.\n",
    "red-bud tree" : "This tree is bright red with blossoms.\n",
    "winding stone path" : "The path winds through the trees.\n",
    "stone path" : "The path winds through the trees.\n",
    "path" : "The path winds through the trees.\n",
    "buds" : "The buds are bright red in color.\n",
    "bud" : "This little bud is bright red.\n",
    "bright petals" : "The petals are bright red in color.\n",
    "petals" : "The petals are bright red in color.\n",
    "fallen buds" : "Fallen buds lies on the path.\n",
    "stone" : "The stone is tinted pink from the fallen buds.\n",
    ]) );
  set("smell", "The scent of flowers drifts in from nearby gardens.\n");
  set("listen"); "You hear birds chirping nearby.\n",
  set("exits", ([
    "north" : P_ROOM+"fountain.c",
    "south" : P_ROOM+"path10.c",
    "east" : P_ROOM+"sunf.c",
    "west" : P_ROOM+"gazebo.c",
    ]) );
  set("objects" , ([
    "canary" : P_MON+"canary.c",
    "butterfly" : P_MON+"butterfly.c",
    ]) );
  reset();
  }
