// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The Bachelor Enlisted Quarters.");
  set("long", @ENDLONG
You stand in a long hallway lined with doors, mostly made of concrete,
with a shabby carpet lining the floor.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(beqrm6),
    "south" : ROOMS(beqrm7),
    "east" : ROOMS(beq5),
    "west" : ROOMS(beq3),
  ]) ) ;
  ::create();
  reset();
}
