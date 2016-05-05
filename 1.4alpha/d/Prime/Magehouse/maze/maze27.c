#include "maze.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{   
    
    ::create();

    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set( "short", "Treasure of Light");
    set( "long", @EndText
Shapes of various creatures both beautiful and beastial float about the room
guarding its treasures, which i suppose are yours now. Do not fear them as they
only hold those who use magic to get here as hostile beings.
EndText
    );
    
    set( "exits", ([              
      "north" : MAZE+"maze27.c"
    ]) );
create_door("north", "south", "blinding flashes of light are all you can make"+
"out of the tiny door before you.", "locked", "light key", 25);
}
