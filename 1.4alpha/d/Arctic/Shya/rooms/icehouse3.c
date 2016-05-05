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
A small fire burning keeps it warm. 
Nothing here but a hole in the floor and a fishing pole
leaning against the wall.
EndText
    );
    set( "exits", ([
 "out" : "/d/Arctic/Shya/rooms/pond.c",
    ]) );
set("item_desc", ([
 "fishing pole" : "This pole leaning against the wall looks old and dusty.\n",
 "pole" : "An old and dusty fishing pole.\n",
 "hole" : "An ordinate fishing hole about the size of a coffee can.\n"
]));
}
