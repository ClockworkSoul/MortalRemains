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
"Brightly colored lilies surround the path in this part of the garden. The "+
"blossoms are large and cheerful, ranging in color from butter yellow to "+
"vibrant orange. You find yourself smiling and whistling as you pass by "+
"the bright blooms."
     ) );
  set("item_desc", ([
    "lilies" : "The lilies are bright and cheerful.\n",
    "lily" : "You stop to admire a large orange lily along the path.\n",
    "path" : "The narrow dirt path winds through the blooms.\n",
    "garden" : "The lily garden is in full bloom.\n",
    "blossoms" : "The blossoms are large and colorful.\n",
    "blossom" : "You stop to admire a large orange lily along the path.\n",
    "bright blooms" : "The blooms range in color from yellow to orange.\n",
    "blooms" : "The blooms range in color from yellow to orange.\n",
    "bloom" : "You stop to admire a large orange bloom along the path.\n",
    ]) );
  set("smell", "The lilies have a surprisingly strong scent.\n");
  set("listen", "You hear only the sound of your own whistling.\n");
  set("exits", ([
    "west" : P_ROOM+"maple.c",
    "southwest" : P_ROOM+"lily2.c",
    "northeast" : P_ROOM+"pool.c",
    ]) );
  set("objects", ([
    "canary": P_MON+"canary.c",
    ]) );
  reset();
  }
