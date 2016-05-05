#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A colorful garden of lilies");
  set("long", wrap(
"You follow a dirt path through a garden of lilies. The flowers range in "+
"color from pale pink to deep purple and sway gently in the light breeze. "+
"Among the thickly planted flowers, you occassionally spot a rabbit or "+
"chipmunk scurrying about."
     ) );
  set("item_desc", ([
    "dirt path" : "The narrow dirt path is surrounded by lilies.\n",
    "path" : "The narrow dirt path is surrounded by lilies.\n",
    "garden" : "The garden of lilies is in full bloom.\n",
    "lilies" : "The lilies range in color from pale pink to deep purple.\n",
    "lily" : "You stop to admire a beautiful pink blossom.\n",
    "flowers" : "The lilies range in color from pale pink to deep purple.\n",
    "flower" : "You stop to admire a beautiful pink blossom.\n",
    "rabbit" : "You see only the ears of a tiny bunny rabbit.\n",
    "chipmunk" : "The chipmunk scurries away when it see you.\n",
    ]) );
  set("smell", "The smell of the lilies is faint but very lovely.\n");
  set("listen", "You hear only the sound of the plants swaying in the "+
      "breeze.\n");
  set("exits", ([
    "north" : P_ROOM+"oak.c",
    "southwest" : P_ROOM+"pond2.c",
    "northeast" : P_ROOM+"lily2.c",
    ]) );
  set("objects", ([
    "chipmunk" : P_MON+"chipmunk.c",
    "bunny" : P_MON+"bunny.c",
    ]) );
  reset();
  }
