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
Looking around you see snow, snow, more snow and footprints
leading south and north. To the North you can see an outline 
of a pond. To the South all you see are more snow covered 
trees.
EndText
    );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/shoreline.c",
      "south" : "/d/Arctic/Shya/rooms/room1.c",
    ]) );

    snowcat = clone_object("/d/Arctic/Shya/monsters/snowcat.c");
    snowcat->move(this_object());
    icegolem = clone_object("/d/Arctic/Shya/monsters/icegolem.c");
    icegolem->move (this_object());
set("item_desc", ([
 "footprints" : "Ordinary footprints leading South and North.\n",
 "snow" : "Cold white stuff.\n",
 "ice" : "Frozen water.\n",
 "pond" : "A body of water smallar than a lake.\n",
 "trees" : "Perennial plants with one main trunk and many branches.\n",
 "igloo" : "Domeshaped and build of blocks of packed snow.\n" 
]));
}
