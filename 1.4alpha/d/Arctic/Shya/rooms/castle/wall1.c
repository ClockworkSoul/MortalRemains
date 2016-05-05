#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Inside the northern Wall (n,s)");
    set( "long", @EndText
You are just inside the castle walls.
EndText
    );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/castle/wall2.c",
      "south" : "/d/Arctic/Shya/rooms/castle/eh1.c"
    ]) );

    frostguard = clone_object("/d/Arctic/Shya/monsters/frostguard.c");
    frostguard->move(TO);

    set( "item_desc", ([
         "walls" : "Simple ice blocks.\n"
]));

}