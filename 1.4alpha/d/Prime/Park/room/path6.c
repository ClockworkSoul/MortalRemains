#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Along a quiet path");
  set("long", wrap(
"Here a red brick path is surrounded by low, cone-shaped shrubs. You peer "+
"over the shrubs and admire the surrounding gardens. A small bird's nest "+
"rests in one of the shrubs, and you hear the faint chirping of the babies "+
"inside."
     ) );
  set("item_desc", ([
    "red brick path" : "The path is narrow here.\n",
    "brick path" : "The path is narrow here.\n",
    "path" : "The path is narrow here.\n",
    "cone-shaped shrubs" : "The shrubs have been trimmed into a cone shape.\n",
    "shrubs" : "The shrubs have been trimmed into a cone shape.\n",
    "shrub" : "This shrub is short and cone-shaped.\n",
    "gardens" : "The surrounding gardens are bright and colorful.\n",
    "small bird's nest" : "Twigs form a tiny nest.\n",
    "bird's nest" : "Twigs form a tiny nest.\n",
    "nest" : "Twigs form a tiny nest.\n",
    "babies" : "Several baby birds chirp in the nest.\n",
    "baby" : "This baby bird is chirping softly.\n",
    ]) );
  set("smell", "You smell the flowers in the surrounding gardens.\n");
  set("listen", "You hear baby birds chirping nearby.\n");
  set("exits", ([
    "east" : P_ROOM+"pool.c",
    "west" : P_ROOM+"path5.c",
    "north" : P_ROOM+"elm.c",
    "south" : P_ROOM+"maple.c",
    ]) );
  set("objects", ([
    "cardinal" : P_MON+"cardinal.c",
    ]) );
  reset();
  }
