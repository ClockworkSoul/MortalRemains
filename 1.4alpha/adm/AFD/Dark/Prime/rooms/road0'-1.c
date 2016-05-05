#include <config.h>
#include <mudlib.h>
#include "../Prime.h"
#include "DESC.c"

inherit ROOM;

void create()
{
  seteuid(getuid());  // need this line if your gonna clone anything.
  set( "light", 1 );
  describe();
  set ("author", "cyanide");
  set( "exits", ([
    "south" : D_PRIMER+"/road0'-2.c",
    "north" : D_PRIMER+"/towncenter.c",
  ]) );
  ::create(); // this also resets the room! :)
  set ("item_desc", ([
   ]) );
}

