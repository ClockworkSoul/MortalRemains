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
Not much to see but snow and ice. To the East is the large castle.
A small path leading towards the castle is covered in snow and footprints. 
EndText
    );
    set( "exits", ([
         "east" : "/d/Arctic/Shya/rooms/room3.c",
    ]) );
    iceguard = clone_object("/d/Arctic/Shya/monsters/iceguard.c");
    if (iceguard)
	iceguard->move (this_object());
    
set ("item_desc", ([
      "footprints" : "These footprints look like a huge bear walked through here.\n",
      "path" : "This well packed down snow leads east.\n",
      "wall" : "Simple ice blocks.\n",
      "snow" : "Cold white stuff.\n",
      "ice" : "Crystalized water.\n",
      "castle" : "Too hard to see from this distance.\n"
]));
}
