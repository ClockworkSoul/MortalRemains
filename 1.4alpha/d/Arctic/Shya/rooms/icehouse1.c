#include <config.h>
#include <mudlib.h>

inherit ROOM;


void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "Antarctica");
    set( "long", @EndText
This icehouse is warm and cozy compaired to outside on the pond.
There is nothing here but a hole in the floor about
the size of a coffee can, and a tiny window in the wall
facing to the Northeast.
EndText
    );
    set( "exits", ([
        "east" : "/d/Arctic/Shya/rooms/pond.c",
    ]) );
set("item_desc", ([
 "window" : "This tiny window faces Northeast over the pond, towards another icehouse.\n"
]));
}
