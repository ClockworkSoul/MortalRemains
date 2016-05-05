#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Inside East Wall (n,s)");
    set( "long", @EndText
You are inside the east wall.
EndText
   );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/castle/wall8.c",
      "south" : "/d/Arctic/Shya/rooms/castle/wall10.c"
    ]) );

   frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
   frostguard->move(TO);
  set( "item_desc", ([
       "wall" : "Simple blocks of ice."
   ]));
}

