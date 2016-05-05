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
set("objects",(["gem" : "/d/Prime/Magehouse/items/ruby.c",
                "gem" : "/d/Prime/Magehouse/items/emerald.c",
                "gem" : "/d/Prime/Magehouse/items/sapphire.c",
]) );
    set( "short", "Rock Room" );
    set( "long", @EndText
This room is carved from natural rock, which comes from the mountains. You
can see flecked throughout the walls traces of valuable metals such as gold,
silver, and iron. There are also treasures for you.

EndText
    );

    set( "exits", ([
      "south" : MAZE+"maze3.c"
    ]) );
create_door("south", "north", "a door of blocked solid stone, glowing "+
"lines of precious metals can be seen within it's construction.",
"locked", "rock key", 25);
}   
