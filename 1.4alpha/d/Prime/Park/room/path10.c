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
"The stone path twists and turns through the blooming red-buds. You notice "+
"many animals move amongst the trees, mostly rabbits and small squirrels. "+
"Above your head, a flock of geese passes, honking loudly and forming "+
"a perfect V in the sky."
     ) );
  set("item_desc", ([
    "stone path" : "The stone path twists and turns.\n",
    "path" : "The path is paved with stone.\n",
    "red-buds" : "The red-buds are in full blooms.\n",
    "trees" : "The red-buds are in full bloom.\n",
    "animals" : "Animals scurry beneath the trees.\n",
    "squirrels" : "Squirrels stop often to gather nuts.\n",
    "rabbit" : "Rabbits hop about merrily.\n",
    "flock of geese" : "The flock forms a perfect V above you.\n",
    "flock" : "The flock forms a perfect V above you.\n",
    "geese" : "The flock forms a perfect V above you.\n",
    ]) );
  set("smell", "You can smell the flowers in the nearby gardens.\n");
  set("listen", "You hear geese honking overhead.\n");
  set("exits", ([
    "north" : P_ROOM+"path9.c",
    "south" : P_ROOM+"pond2.c",
    "east" : P_ROOM+"oak.c",
    "west" : P_ROOM+"willow.c",
    ]) );
  set("objects", ([
    "bunny" : P_MON+"bunny.c",
    "squirrel" : P_MON+"squirrel.c",
    ]) );
  reset();
  }
