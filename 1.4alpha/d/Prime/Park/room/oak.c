#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "In an alley of oak trees");
  set("long", wrap(
"A wide path is flanked by rows of giant oak trees. The path is made of "+
"stone and extends far into the distance. You pause and marvel at the "+
"elegant walkway. Birds chip overhead in the trees, and occassionally "+
"a squirrel or chipmunk will scurry across the path."
     ) );
  set("item_desc", ([
    "wide path" : "The wide path extends far into the distance.\n",
    "path" : "The path is paved with stone.\n",
    "rows" : "Rows of oak trees line the path.\n",
    "row" : "Rows of oak trees line the path.\n",
    "giant oak trees" : "The trees are huge! They must be very old.\n",
    "oak trees" : "The trees are huge! They must be very old.\n",
    "trees" : "The trees are huge! They must be very old.\n",
    "oaks" : "The trees are huge! They must be very old.\n",
    "tree" : "You stop to marvel at the giant tree before you.\n",
    "oak" : "You stop to marvel at the giant tree before you.\n",
    "oak tree" : "You stop to marvel at the giant tree before you.\n",
    "stone" : "The stone is grey in color.\n",
    "walkway" : "The walkway is paved with stone.\n",
    "birds" : "You peer into the trees but do not see any birds.\n",
    "squirrels" : "A squirrel quickly scurries past.\n",
    "chipmunk" : "A chipmunk quickly scurries past.\n",
    ]) );
  set("smell", "You inhale and only faintly detect the scent of flowers in "+
      "the distance.\n");
  set("listen", "You hear birds chirping in the trees overhead.\n");
  set("exits", ([
    "west" : P_ROOM+"path10.c",
    "south" : P_ROOM+"lily1.c", 
    ]) );
  set("objects", ([
    "squirrel" : P_MON+"squirrel.c",
    "woodpecker" : P_MON+"woodpecker.c",
    "chipmunk" : P_MON+"chipmunk.c",
    ]) );
  reset();
  }
