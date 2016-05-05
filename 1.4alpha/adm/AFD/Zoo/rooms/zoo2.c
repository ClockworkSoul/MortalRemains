#include <mudlib.h>           
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("light", 1);
  set( "short", "The Petting Zoo." );
  set( "long", @ENDLONG
You are in a small petting zoo.
ENDLONG
  );
  set( "exits", ([
    "south" : ROOMS(zoo1),
    "east" : ROOMS(zoo4),
  ]) );
  ::create();
  fill_room(1);
}

reset() {
  if (!present("#BLAH#", TO)) fill_room();
}
