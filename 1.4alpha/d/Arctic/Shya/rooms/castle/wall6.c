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
    set("short", "Northeast Corner of Castle (w,s)");
    set( "long", @EndText
You are in the northeast corner of the castle walls.
There is a window facing the north.
EndText
   );
    set( "exits", ([
      "west" : "/d/Arctic/Shya/rooms/castle/wall5.c",
      "south" : "/d/Arctic/Shya/rooms/castle/wall7.c"
    ]) );

  set( "item_desc", ([
    "window" : "You look through the window and see a pond in the distance.",
    "pond" : "A huge pond iced over and covered with icehouses towards the north."
]));

   frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
   frostguard->move(TO);

}

 
     
