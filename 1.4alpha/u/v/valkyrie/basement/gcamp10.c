#include "basement.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set("objects",([
    "gnome" : "/d/Prime/Magehouse/monsters/gnome1.c",
    "gnome" : "/d/Prime/Magehouse/monsters/gnome1.c",
    "gnome" : "/d/Prime/Magehouse/monsters/gnome1.c",
    ]) );
    reset();
    set( "light", 1 );
    set("author","blood");
    set( "short", "Gnome Encampment" );
    set( "long", @EndText
This level has been painstakingly constructed to conform even with the
dwarven standards of mine construction. Veins of various types of precious
ore can be seen flowing through the walls and all of the gnomes here seem
to be hard at work constructing new areas and living space and for profit.
EndText
    );
    
    set( "exits", ([   
      "south" : BSMNT+"gcamp11.c",
      "north" : BSMNT+"gcamp9.c",
      "west" : BSMNT+"platform4.c",
    ]) );
}
