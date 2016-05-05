#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Before a graceful statue");
  set("long", wrap(
"Benches are placed in a circle here, surrounding a towering statue of a "+
"dancer. The woman depicted reaches her hands up to the sky, encircled by "+
"her flowing gowns. The statue, obviously the work of a fine artist, is "+
"quite moving and realistic."
     ) );
  set("item_desc", ([
    "benches" : "The benches are made of wood and have been painted green.\n",
    "bench" : "This bench is made of wood and has been painted green.\n",
    "circle" : "A circle of benches surrounds the statue.\n",
    "towering statue" : "The statue towers above you, reaching to the sky.\n",
    "statue" : "The statue depicts a dancing woman.\n",
    "dancer" : "The dancer reaches up to the sky as she twirls.\n",
    "woman" : "The woman reaches up to the sky as she twirls.\n",
    "hands" : "The woman's hands extend to the sky.\n",
    "sky" : "The sky above is dotted with clouds.\n",
    "flowing gowns" : "The woman's gowns encircle her.\n",
    "gowns" : "The woman's gowns encircle her.\n",
    ]) );
  set("smell", "You smell flower in nearby gardens.\n");
  set("listen", "You hear birds chirping in the distance.\n");
  set("exits", ([
    "south" : P_ROOM+"path2.c",
    ]) );
  set("objects", ([
    "pigeon" : P_MON+"pigeon.c",
    "spider" : P_MON+"spider.c",
    ]) );
  reset();
  }
