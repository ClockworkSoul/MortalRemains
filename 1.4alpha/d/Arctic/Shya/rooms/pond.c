#include <config.h>
#include <mudlib.h>

inherit ROOM;

object snowman;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");   
    set( "light", 1 );
    set("short", "Antarctica");
    set( "long", @EndText
This pond is covered in very thick ice,
but in places it is thin so be careful you might fall in.
There are still footprints headed North, South, East, and West.
To the North you see an icehouse with smoke coming out of the chimney.
To the South you see the shoreline of this pond and more footprints,
making it look well travelled.
To the East and West you see more icehouses.
EndText
    );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/icehouse2.c",
      "south" : "/d/Arctic/Shya/rooms/shoreline.c",
      "east" : "/d/Arctic/Shya/rooms/icehouse3.c",
      "west" : "d/Arctic/Shya/rooms/icehouse1.c",
    ]) );
    snowman = clone_object("/d/Arctic/Shya/monsters/snowman.c");
    snowman->move (this_object());
set("item_desc", ([
 "footprints" : "Ordinary footprints leading South and North.\n",
 "smoke" : "A vaporous matter arising from something burning.\n",
 "icehouse" : "A small building sitting on ice.\n",
 "icehouses" : "A few small buildings sitting on ice.\n",
 "pond" : "A body of water smallar than a lake.\n",
 "trees" : "Perennial plants with one main trunk and many branches.\n",
 "igloo" : "Domeshaped and build of blocks of packed snow.\n", 
 "ice#thick ice" : "The ice is thick.\n",
 "chimney" : "A structure through which smoke escapes from a fire.\n",
 "shoreline" : "A landmass surrounding a body of water.\n"
]));
}
