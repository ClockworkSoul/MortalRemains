#include <config.h>
#include <mudlib.h>
#include "../Prime.h"

inherit ROOM;

void create()
{
  seteuid(getuid());  // need this line if your gonna clone anything.
  set( "light", 1 );
  set ("short", "The Future Site of a Magic Shop");
  set( "long", @EndText
This will be a magic shoppe someday.
EndText
  );
  set ("author", "cyanide");
  set( "exits", ([
    "north" : D_PRIMER+"/road2'0.c",
  ]) );
  ::create(); // this also resets the room! :)
  set ("item_desc", ([
   ]) );
}

