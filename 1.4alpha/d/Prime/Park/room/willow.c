#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Beneath a graceful willow");
  set("long", wrap(
"A graceful willow tree sits here, its long branches swaying gently in the "+
"breeze. The area beneath the tree looks like the perfect place for a picnic "+
"or to relax with a book on a warm day. The grass here is bright green and "+
"very soft beneath you."
     ) );
  set("item_desc", ([
    "graceful willow tree" : "The willow tree is tall and graceful.\n",
    "willow tree" : "The willow tree is tall and graceful.\n",
    "tree" : "The willow tree is tall and graceful.\n",
    "willow" : "The willow tree is tall and graceful.\n",
    "long branches" : "The long branches nearly touch the ground.\n",
    "branches" : "The long branches nearly touch the ground.\n",
    "grass" : "The grass is thick and soft.\n",
    ]) );
  set("smell", "You smell the scent of the freshly cut grass.\n");
  set("listen", "You hear birds chirping in the willow tree.\n");
  set("exits", ([
    "south" : P_ROOM+"rose3.c",
    "east" : P_ROOM+"path10.c",
    ]) );
  set("objects", ([
    "fawn" : P_MON+"fawn.c",
    "sparrow" : P_MON+"sparrow.c",
    "cardinal" : P_MON+"cardinal.c",
    ]) );
  reset();
  }
