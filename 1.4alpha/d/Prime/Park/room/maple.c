#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A grove of maples");
  set("long", wrap(
"Several maple trees have been planted in this section of the park. Their "+
"leaves provide large shady areas in which to relax and cool off. A wooden "+
"bench lies beneath one tall tree. As you look around, you notice several "+
"trees are being tapped for their syrup."
     ) );
  set("item_desc", ([
    "maple trees" : "The leafy trees provide shade in this area.\n",
    "trees" : "The leafy trees provide shade in this area.\n",
    "shade" : "The shade is cool and relaxing.\n",
    "large shady areas" : "The shade is cool and relaxing.\n",
    "shady areas" : "The shade is cool and relaxing.\n",
    "leaves" : "The leaves are bright green in color.\n",
    "leaf" : "You stop to admire the unique shape of a leaf.\n",
    "wooden bench" : "The bench looks old and well-worm.\n",
    "bench" : "The bench looks old and well-worn.\n",
    "tall tree" : "A towering maple provides shade for the bench.\n",
    "tree" : "A towering maple provides shade for the bench.\n",
    "maple" : "A towering maple provides shade for the bench.\n",
    ]) );
  set("smell", "You smell the fresh scent of grass.\n");
  set("listen", "You hear the wind as it blows through the leaves.\n");
  set("exits", ([
    "north" : P_ROOM+"path6.c",
    "east" : P_ROOM+"lily3.c", 
    ]) );
  set("objects", ([
    "fawn" : P_MON+"fawn.c",
    ]) );
  reset();
  }
