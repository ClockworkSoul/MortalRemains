// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A narrow hallway in the castle.");
  set("long", "You stand in a narrow hallway on the north side of the castle.\n");
  set("light", 1) ;
  set("exits", ([
  "south" : ROOMS(family29),
    "east" : ROOMS(Nhall3.c),
    "west" : ROOMS(Nhall5.c),
  ]) ) ;
  ::create();
}
