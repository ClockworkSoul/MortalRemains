
#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "SouthWest Corner of Castle (n,e)");
    set( "long", @EndText
You are in the southwest corner wall of the castle.
A window faces to the west. Other than that nothing out of
the ordinary for a castle wall.
EndText
   );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/castle/wall15.c",
      "east" : "/d/Arctic/Shya/rooms/castle/wall13.c",
      "west" : "/d/Arctic/Shya/rooms/forest1.c"
    ]) );

  set( "item_desc", ([
    "window" : "You look through the window and see lots of trees off with a path through them.\n",
    "pond" : "A huge pond iced over and covered with icehouses.\n",
    "wall" : "Simple ice blocks.\n",
    "path" : "A passage through the trees to the west.  Maybe you should follow it.\n"
]));

   frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
   frostguard->move(TO);

}
void reset()
{
	if (! frostguard) {
		frostguard = clone_object("/d/Arctic/Shya/monsters/frostguard.c");
		frostguard->move(TO);
	}
      
}
