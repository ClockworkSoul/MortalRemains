#include <config.h>
#include <mudlib.h>

inherit ROOM;

object snowman, snowcat;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "Antarctica");
    set( "long", @EndText
This looks to be the shoreline of a huge pond covered in ice. 
More footprints are around the shoreline and some look to be 
headed North across the pond. To the North you see the outline 
of an icehouse sitting in the middle of the pond. To the South 
all you see are more snow covered trees.
EndText
    );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/pond.c",
      "south" : "/d/Arctic/Shya/rooms/room2.c",
	"east" : "/d/Arctic/Shya/rooms/castle/stables.c"
    ]) );

    snowcat = clone_object("/d/Arctic/Shya/monsters/snowcat.c");
    snowcat->move(this_object());
    snowman = clone_object("/d/Arctic/Shya/monsters/snowman.c");
    snowman->move (this_object());
set("item_desc", ([
 "footprints" : "Ordinary footprints leading South and North.\n",
 "icehouse" : "A small building sitting on ice.\n",
 "ice" : "Frozen water.\n",
 "pond" : "A body of water smallar than a lake.\n",
 "trees" : "Perennial plants with one main trunk and many branches.\n",
 "igloo" : "Domeshaped and build of blocks of packed snow.\n" 
]));
}
