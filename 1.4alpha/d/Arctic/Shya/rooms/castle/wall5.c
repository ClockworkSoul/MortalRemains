
#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Inside North Wall (e,w)");
    set( "long", @EndText
You are inside the north wall.
EndText
   );
    set( "exits", ([
      "west" : "/d/Arctic/Shya/rooms/castle/wall4.c",
      "east" : "/d/Arctic/Shya/rooms/castle/wall6.c"
    ]) );

   frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
   frostguard->move(TO);
  set( "item_desc", ([
    "wall" : "Simple ice blocks.\n"
]));
}

