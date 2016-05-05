
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
   "north" : ROOMS(zoo7),
    "south" : ROOMS(zoo3),
    "east" : ROOMS(zoo6),
    "west" : ROOMS(zoo2),
  ]) );
  ::create();
  fill_room(1);
}

void
reset() {
  if (!present("#BLAH#", TO)) fill_room(0);
}

void init() {
  add_action("pet", "pet") ;
}
int pet() {
  write("You don't feel like petting.. you feel like killing.\n") ;
  return 1;
}
