#include <config.h>
#include <mudlib.h>

inherit ROOM;

object icegolem, snowcat;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "Antarctica");
    set( "long", @EndText
This blizzardry of a place is covered in snow and ice.
Looking around you see nothing but snow and a few footprints
leading to the south and the north. This wintery wonderland 
makes you wish you were home next to a warm fire.
EndText
    );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/room2.c",
      "south" : "/d/Arctic/Shya/rooms/room3.c",
    ]) );

    snowcat = clone_object("/d/Arctic/Shya/monsters/snowcat.c");
    snowcat->move(this_object());
    icegolem = clone_object("/d/Arctic/Shya/monsters/icegolem.c");
    icegolem->move (this_object());
set("item_desc", ([
 "footprints" : "Ordinary footprints leading South and North.\n",
 "snow" : "Cold white stuff.\n"
]));
}
