#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "In the shade of an elm tree");
  set("long", wrap(
"Above you looms a towering elm tree. Its branches reach magestically to "+
"the sky, and it is so tall that you cannot even see the top. It provides "+
"a large shady area in which to relax and cool off on a warm day. You feel "+
"very safe and protected here."
     ) );
  set("item_desc", ([
    "towering elm tree" : "The elm reaches magestically toward the sky.\n",
    "elm tree" : "The elm reaches magestically toward the sky.\n",
    "elm" : "The elm reaches magestically toward the sky.\n",
    "tree" : "The elm reaches magestically toward the sky.\n",
    "branches" : "The branches reach up toward the sky.\n",
    "branch" : "A thick branch extends from the elm tree.\n",
    "sky" : "The sky above is obscured by the elm tree.\n",
    "shade" : "The shade provides a nice place to relax and cool off.\n",
    "shady area" : "The shade provides a nice place to relax and cool off.\n",
    ]) );
  set("smell", "You inhale and smell the freshly cut grass beneath you.\n");
  set("listen", "You listen carefully but hear only the soft rustling of "+
      "the leaves.\n");
  set("exits", ([
    "south" : P_ROOM+"path6.c",
    "east" : P_ROOM+"orchard3.c",
    ]) );
  set("objects", ([
    "cardinal" : P_MON+"cardinal.c",
    "squirrel" : P_MON+"squirrel.c",
    ]) );
  reset();
  }
