#include <mudlib.h>
#include "generic/GenericLib.h"

inherit ROOM;
inherit GLibDir+"populate_generic_monsters.c";

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "A monster room" );
  set( "long", "Some monsters might be here.\n" );
  set( "exits", ([
    "workroom" : "/u/g/grull/workroom.c",
  ]) );
 
  populate_generic_monsters(TO);

}

void foo(){
  write("Testing\n");
}
