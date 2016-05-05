
#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Inside South Wall (n,s)");
    set( "long", @EndText
You are inside the South wall.
EndText
   );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/room3.c",
      "south" : "/d/Arctic/Shya/rooms/castle/wall14.c"
    ]) );

   frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
   frostguard->move(TO);
 set ("item_desc", ([
      "wall" : "A tall and solid structure holding up the castle.\n"

]));
}
