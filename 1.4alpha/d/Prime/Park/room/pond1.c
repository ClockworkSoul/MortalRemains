#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Near a tranquil pond");
  set("long", wrap(
"White lily-pads dot the clear water of the pond. Small reeds rise out of "+
"the water along the far bank and sway slowly in the soft breeze. Small "+
"ripples move along the water, and you occassionally notice movement "+
"beneath the surface."
     ) );
  set("item_desc", ([
    "lily-pads" : "The lily pads are bright white.\n",
    "lily-pad" : "The lily-pad is bright white.\n",
    "clear water" : "You peer into the water and see your reflection.\n",
    "water" : "You peer into the water and see your reflection.\n",
    "pond" : "The pond is large and clear.\n",
    "small reeds" : "The reeds sway in the breeze.\n",
    "small reed" : "The small reed sways in the breeze.\n",
    "reeds" : "The reeds sway in the breeze.\n",
    "reed" : "The small reed sways in the breeze.\n",
    "far bank": "Reeds rise near the far bank.\n",
    "bank" : "Reeds rise near the far bank.\n",
    "small ripples" : "Ripples roll along the pond.\n",
    "ripples" : "Ripples roll along the pond.\n",
    "movement" : "You see movement beneath the surfance.\n",
    "surface" : "The surface is lined with small ripples.\n",
    ]) );
  set("smell", "You smell the flowers in the nearby gardens.\n");
  set("listen", "You hear frogs croaking nearby.\n");
  set("exits", ([
    "south" : P_ROOM+"path7.c",
    "southwest" : P_ROOM+"veg3.c",
    "southeast" : P_ROOM+"orchard1.c",
    ]) );
  set("objects", ([
    "toad" : P_MON+"toad.c",
    "worm" : P_MON+"worm.c",
    "frog" : P_MON+"frog.c",
    ]) );
  reset();
  }
