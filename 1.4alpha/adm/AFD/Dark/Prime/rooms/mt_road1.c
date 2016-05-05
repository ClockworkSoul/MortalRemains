#include "../Prime.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  seteuid(getuid());  // need this line if your gonna clone anything.
  set( "light", 1 );
  set ("short", "On a rocky mountain road");
  set( "long", @EndText
The forest surrounding you is thick with vegetation.  You wonder
how such vegetation could survive in such a horrid climate.  Every
breath you take is laden with the smell of brimstone and ash. The
mountain road you now stand on begins to steepen as the road curves to
the northwest.
EndText
  );
  set ("author", "cyanide/waxer");
  set( "exits", ([
    "east" : D_PRIMER+"/lavaview.c",
    "northwest" : D_PRIMER+"/mt_road2.c",
  ]) );
  ::create(); // this also resets the room! :)
  set ("item_desc", ([
   ]) );
}
