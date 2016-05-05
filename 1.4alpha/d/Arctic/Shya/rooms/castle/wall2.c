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
    set("short", "Northwest Corner of Castle (s,e)");
    set( "long", @EndText
This is the northwest corner of the castle. 
You are just inside the castle walls. Windows align the walls.
EndText
   );
    set( "exits", ([
      "south" : "/d/Arctic/Shya/rooms/castle/wall1.c",
      "east" : "/d/Arctic/Shya/rooms/castle/wall3.c",
	"north" : "/d/Arctic/Shya/rooms/castle/stables.c"
    ]) );

    set( "item_desc", ([
        "windows" : "You look throught this window and see an igloo and some icehouses to the north.",
        "walls" : "Simple ice blocks with a lot of windows."
    ]));

   frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
   frostguard->move(TO);

}
