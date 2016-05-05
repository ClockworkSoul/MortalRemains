#include <config.h>
#include <mudlib.h>

inherit ROOM;

object icegolem, blackdog;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "King's stables");
    set( "long", @EndText
This is where the King keeps his finest horses. These horses have fed on the Grains of Tefnut
and can run across water. They have been trained to find the main village.
EndText
    );
    set( "exits", ([
      "west" : "/d/Arctic/Shya/rooms/shoreline.c",
	"south" : "/d/Arctic/Shya/rooms/castle/wall2.c"
    ]) );

    blackdog = clone_object("/d/Arctic/Shya/monsters/blackdog.c");
    blackdog->move(this_object());

    icegolem = clone_object("/d/Arctic/Shya/monsters/icegolem.c");
    icegolem->move (this_object());
set("item_desc", ([
 "stables" : "It is filled with various items for maintaining horses.\n",
"horses" : "These majestic horses are the pride of the king's collection."
]));
}

