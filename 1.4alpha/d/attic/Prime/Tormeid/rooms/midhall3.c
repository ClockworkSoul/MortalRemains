// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway in the castle.");
  set("long", "This large hallway runs north and south through the center of the castle.\n");
  set("light", 1) ;
  set("exits", ([
  "west" : ROOMS(family4),
  "east" : ROOMS(family3),
    "south" : ROOMS(midhall2.c),
    "north" : ROOMS(midhall4.c),
  ]) ) ;
  ::create();
}
