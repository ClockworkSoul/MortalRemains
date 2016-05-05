#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Beneath a giant sycamore");
  set("long", wrap(
"Giant sycamore trees surround you, casting a large, cool shadow on the "+
"ground. You glance up and see only bits of the sky peeking out between the "+
"large leaves. Several leaves lie on the ground, crunching beneath your "+
"feet when you walk."
     ) );
  set("item_desc", ([
    "giant sycamore trees" : "The giant sycamores tower above you.\n",
    "sycamore trees" : "The giant sycamores tower above you.\n",
    "sycamores" : "The giant sycamores tower above you.\n",
    "trees" : "The giant sycamores tower above you.\n",
    "shadow" : "The trees cast a large, cool shadow.\n",
    "ground" : "Fallen leaves lie on the ground.\n",
    "sky" : "The sky is obscured by the large trees.\n",
    "large leaves" : "Large leaves lie fallen on the ground.\n",
    "leaves" : "Large leaves lie fallen on the ground.\n",
    "tree" : "This tree is tall and magestic.\n",
    "sycamore" : "This tree is tall and magestic.\n",
    "leaf" : "This leaf is quite large.\n",
    ]) );
  set("smell", "You smell the flowers in nearby gardens.\n");
  set("listen", "You hear the leaves rustling in the breeze.\n");
  set("exits", ([
    "north" : P_ROOM+"veg3.c",
    "east" : P_ROOM+"path7.c",
    ]) );
  set("objects", ([
    "owl" : P_MON+"owl.c",
    "robin" : P_MON+"robin.c",
    ]) );
  reset();
  }
