// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "A narrow hallway in the castle.");
  set("long", "You stand in a narrow hallway on the north side of the castle.\n");
  set("light", 1) ;
  set("exits", ([
  "east" : ROOMS(netower1),
    "west" : ROOMS(Nhall2.c),
  ]) ) ;
  ::create();
}
