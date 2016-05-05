// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Pacific Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Pacific Avenue on Naval Station Norva.
A huge mansion lies to the east.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base16),
    "south"  : ROOMS(base18),
    "east"  : ROOMS(admiral),
  ]) ) ;
  ::create();
  reset();
}
void init() {
  add_action("go", "go") ;
}

int go(string str) {
  if (!str || str != "east") return 0 ;
  write("The doors to the mansion are locked tightly.\n") ;
 return 1;
}
