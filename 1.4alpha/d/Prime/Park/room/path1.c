#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Along a cobblestone path");
  set("long", wrap(
"You follow a cobblestone path in Balitor Park. Small shrubs flank the "+
"path, and some are dotted with bright red berries. As you look into "+
"the distance, you see brightly colored flowers and towering trees. "+
"Everything in the park seems to be in full bloom."
     ) );
  set("item_desc", ([
    "cobblestone path" : "A cobblestone path leads into the park.\n",
    "path" : "The path is paved with cobblestones.\n",
    "small shrubs" : "Shrubs flank the path.\n",
    "shrubs" : "Shrubs flank the path.\n",
    "shrub" : "You stop to admire a dark green shrub.\n",
    "small shrub" : "You stop to admire a dark green shrub.\n",
    "bright red berries" : "Bright red berries dot several of the shrubs.\n",
    "red berries" : "Bright red berries dot several of the shrubs.\n",
    "berries" : "Bright red berries dot several of the shrubs.\n",
    "berry" : "This berry is round and ripe.\n",
    "red berry" : "This berry is round and ripe.\n",
    "flowers" : "Colorful flowers bloom in the distance.\n",
    "towering trees" : "The trees in the distance look huge!\n",
    "trees" : "The trees in the distance look huge!\n",
    ]) );
  set("smell", "The scent of flowers drifts in on the breeze.\n");
  set("listen", "It is quiet and peaceful here.\n");
  set("exits", ([
    "east" : P_ROOM+"path2.c",
    "west" : P_ROOM+"enter.c",
    "north" : P_ROOM+"magnolia.c",
    "south" : P_ROOM+"dogwood.c",
    ]) );
  set("objects", ([
    "ladybug" : P_MON+"ladybug.c",
    ]) );
  reset();
  }

