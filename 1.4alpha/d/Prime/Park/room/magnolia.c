#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Surrounded by magnolia trees");
  set("long", wrap(
"Blooming magnolia trees surround you in this section of the park. Healthy "+
"green grass lies beneath you, marred only by a small hole near one tree. "+
"You occassionally see movement in the direction of the hole, but you "+
"can never get a good look at what lives there."
     ) );
  set("item_desc", ([
    "magnolia trees" : "The magnolia trees are in full bloom.\n",
    "trees" : "The magnolia trees are in full bloom.\n",
    "magnolia" : "The magnolia tree is covered in blossoms.\n",
    "tree" : "The magnolia tree is in full bloom.\n",
    "healthy green grass" : "The grass is green and lush.\n",
    "green grass" : "The grass is green and lush.\n",
    "grass" : "The grass is green and lush.\n",
    "small hole" : "You peer into the hole, but it is too dark to see "+
      "anything.\n",
    "hole" : "You peer into the hole, but it is too dark to see anything.\n",
    ]) );
  set("smell", "The air is sweet with the scent of magnolia blossoms.\n");
  set("listen", "You occassionally hear rustling from the direction of "+
    "the hole.\n");
  set("exits", ([
    "west" : P_ROOM+"veg1.c",
    "south" : P_ROOM+"path1.c",
    ]) );
  set("objects", ([
    "ladybug" : P_MON+"ladybug.c",
    "centipede" : P_MON+"centipede.c",
    ]) );
  reset();
  }
