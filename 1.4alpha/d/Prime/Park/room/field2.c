#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A playing field");
  set("long", wrap(
"A large field stretches out before you. It is covered by long grass that "+
"sways gently in the breeze. You hear rustling in the grass beneath you "+
"and occassionally see a chipmunk peek its head out to examine you."
     ) );
  set("item_desc", ([
    "large field" : "The large field is covered in grass.\n",
    "field" : "The field is large and covered in grass.\n",
    "long grass" : "The long grass sways in the breeze.\n",
    "grass" : "The long grass sways in the breeze.\n",
    "chipmunk" : "The chipmunk disappears back into its hole before you can "+
      "get a good look at it.\n",
    ]) );
  set("smell", "You inhale and enjoy the fresh scent of the grass.\n");
  set("listen", "You hear rustling in the grass beneath you.\n");
  set("exits", ([
    "south" : P_ROOM+"path5.c",
    ]) );
  set("objects", ([
    "chipmunk" : P_MON+"chipmunk.c",
    ]) );
  reset();
  }
