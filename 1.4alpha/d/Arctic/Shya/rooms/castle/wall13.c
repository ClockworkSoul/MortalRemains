#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Inside South Wall (e,w)");
    set( "long", @EndText
You are inside the South wall.
EndText
   );
    set( "exits", ([
      "west" : "/d/Arctic/Shya/rooms/castle/wall14.c",
      "east" : "/d/Arctic/Shya/rooms/castle/wall12.c",
      "south" : "/d/Arctic/Shya/rooms/castle/recroom.c",
      "north" : "/d/Arctic/Shya/rooms/castle/eh3.c"
    ]) );

   frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
   frostguard->move(TO);

 set( "item_desc", ([
      "wall" : "Simple ice blocks.\n"
]));
}
