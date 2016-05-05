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
There is nothing here but a hole in the floor about the size
of a coffee can, and a small fire burning, keeping it warm in here
and letting the smoke out the chimney.
EndText
    );
    set( "exits", ([
 	"south" : "/d/Arctic/Shya/rooms/pond.c",
	"north" : "/d/Arctic/Shya/rooms/igloo.c"
    ]) );
set("item_desc", ([
 "smoke" : "A vaporous matter arising from something burning.\n",
 "icehouse" : "A small building sitting on ice.\n",
 "pond" : "A body of water smallar than a lake.\n",
 "chimney" : "A structure through which smoke escapes from a fire.\n",
 "hole" : "An opening in the floor,\n",
 "floor" : "The bottom surface of the icehouse.\n",
 "fire" : "The flame, light, and heat of combustion.\n"
]));
}
