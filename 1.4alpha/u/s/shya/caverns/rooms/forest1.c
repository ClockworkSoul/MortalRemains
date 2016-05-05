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
The entire forest is covered in snow and ice.
Looking around you see nothing but snow and a few footprints.
This wintery wonderland makes you wish you were home
next to a warm fire.
EndText
    );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/caverns/rooms/forest1.c",
      "south" : "/d/Arctic/Shya/caverns/rooms/forest2.c",
    ]) );

    snowcat = clone_object("/d/Arctic/Shya/monsters/snowcat.c");
    snowcat->move(this_object());
    icegolem = clone_object("/d/Arctic/Shya/monsters/icegolem.c");
    icegolem->move (this_object());
set("item_desc", ([
 "footprints" : "Ordinary footprints leading East and North.\n"
]));
}
