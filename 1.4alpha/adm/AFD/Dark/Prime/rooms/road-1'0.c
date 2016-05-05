#include <config.h>
#include <mudlib.h>
#include "../Prime.h"
#include "DESC.c"

inherit ROOM;

void create()
{
  seteuid(getuid());  // need this line if your gonna clone anything.
  describe();
  set( "light", 1 );
  set ("author", "cyanide");
  set( "exits", ([
    "east" : D_PRIMER+"/towncenter.c",
  ]) );
  ::create(); // this also resets the room! :)
  set ("item_desc", ([
   ]) );
}

