// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A narrow hallway in the castle.");
  set("long", "You stand in a long, narrow hallway on the south side of the castle.\n");
  set("light", 1) ;
  set("exits", ([
   "west" : ROOMS(s_stairs-1),
    "east" : ROOMS(Shall5.c),
  ]) ) ;
  ::create();
}
