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
    "north" : D_PRIMER+"/road0'-1.c",
  ]) );
  ::create(); // this also resets the room! :)
  set ("item_desc", ([
   ]) );
}

