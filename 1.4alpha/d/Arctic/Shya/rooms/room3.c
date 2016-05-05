#include <config.h>
#include <mudlib.h>

inherit ROOM;
object iceguard;
void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "Antarctica");
    set( "long", @EndText
Not much to see but snow and ice, although in a distance you
see a castle to the East. A small path leading West is covered
in snow. 
EndText
    );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/room1.c",
      "west" : "/d/Arctic/Shya/rooms/room4.c",
      "east" : "/d/Arctic/Shya/rooms/castle/eh1.c",
      "south" : "/d/Arctic/Shya/rooms/castle/wall15.c"
    ]) );
    iceguard = clone_object("/d/Arctic/Shya/monsters/iceguard.c");
    if (iceguard)
	iceguard->move (this_object());
    set ("item_desc", ([
      "footprints" : "These footprints look like a huge bear walked through here.\n",
      "path" : "A well travelled passage covered in snow.\n",
      "castle" : "It is hard to see from this distance.\n",
      "snow" : "Cold white stuff.\n",
      "ice" : "Crystalized water.\n"
    ]));
}
