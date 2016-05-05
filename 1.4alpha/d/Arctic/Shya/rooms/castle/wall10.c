#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "SouthEast Corner of Castle (n,w)");
    set( "long", @EndText
You are inside the walls of the southeast corner of the
castle.  There is a ladder leading down, but it seem 
broken and the distance is too far to jump.  Maybe in
the future, it will be operational.
EndText
   );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/castle/wall9.c",
      "west" : "/d/Arctic/Shya/rooms/castle/wall11.c"
    ]) );

  set( "item_desc", ([
      "wall" : "Simple ice bloacks",
      "ladder" : "It looks unsafe, so you avoid it."
]));

   frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
   frostguard->move(TO);

}

